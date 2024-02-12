#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

	// declare your variables
    int pal_length = 0;
    bool has_odd = false;
    int num;
    string input;

	// read the input
	cin >> num;
    cin >> input;

	// solve, good luck!
    unordered_map<char, int> char_counts; //create key value pairs of each letter and the number of times it occurs
    for (const char& c : input) { // iterate through characters of input string
        if (char_counts.find(c) == char_counts.end()){
            char_counts[c]=0;
        }
        char_counts[c]++;
    }

    for (const auto entry : char_counts) { // iterate over key value pairs in map
        int count = entry.second; //character is first entry; count is second
        if (count % 2 == 0) {
            pal_length += count; // increases for even instances
        } else {
            pal_length += count - 1; // subtracts to become even then increases
            has_odd = true; // flag for next step
        }
    }

    if (has_odd) {
        pal_length++; // add 1 for the letter in the middle of the palindrome
    }

    cout << pal_length << endl;
	
}
