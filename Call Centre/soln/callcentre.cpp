#include <iostream>
using namespace std;

int main() {
    int n;
    int q;
    int s;
    int t;
    // Read in the input
    cin >> n >> q;
    int el[n];
    for (int i=0; i < n; i++){
        cin >> el[i];
    }
    int prefixSum[n];
    prefixSum[0] = el[0];
    for (int i=1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + el[i];
    }
    // Solve the problem
    for (int i=0; i < q; i++){
        cin >> s >> t;
        int sum  = 0;
        if (s == 1) {
            sum = prefixSum[t-1];
        } 
        else {
            sum = prefixSum[t-1] - prefixSum[s-2];
        }
    // Output the result
    cout << sum << endl;
    }


    return 0;
}