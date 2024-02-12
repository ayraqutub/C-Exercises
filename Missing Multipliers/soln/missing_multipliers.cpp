#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long> a(n), front(n), back(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Construct front-rolling and back-rolling product arrays
    front[0] = a[0];
    back[n-1] = a[n-1];
    for (int i = 1; i < n; i++) {
        front[i] = front[i-1] * a[i];
    }
    for (int i = n-2; i >= 0; i--) {
        back[i] = back[i+1] * a[i];
    }

    // Calculate the product for each index
    for (int i = 0; i < n; i++) {
        int start = max(0, i-m);
        int end = min(n-1, i+m);

        long prod = 1;
		
        if (start > 0 && end == n - 1) {
            prod = front[start-1];
        }
        if (start == 0 && end < n - 1) {
            prod = back[end+1];
        }
		if (start > 0 && end < n - 1) {
            prod = front[start-1] * back[end+1];
        }
		if (start == 0 && end == n-1){
			prod = 0;
		}
        cout << prod;
		if (i <n -1){
			cout <<" ";
		}
    }
	cout << endl;
    return 0;
}
