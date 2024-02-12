#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

  // declare variables
  int startAddr;
  int numEl;
  int count;
  int add;
  unordered_set<int> set;

  // read the input
  cin >> startAddr;
  cin >> numEl;
  int el[numEl];
  for (int i=0; i < numEl; i++){
    cin >> el[i];
  }
  int ptr = el[0];

  // solve the problem
  while (count != numEl){ 
    if (ptr >= 0){ // memory address
      add = ptr-startAddr; 
      ptr = el[add]; 
      count++;
      if (set.count(ptr) != 0){ // repeat value
        cout << "There was a cycle" << endl;
        break;         
    }
    set.insert(ptr);
    }
    else{ // value
      cout << ptr << endl;
      break;
    }
  }

  return 0;
}
