#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    vector<pair<int, int>> glasses(n);
    for (int i = 0; i < n; ++i) {
        cin >> glasses[i].first >> glasses[i].second;
    }

    int time = glasses[k].first * t;
    int target = glasses[k].second;
    while (target != -1) {
        time += glasses[target].first * t;
        target = glasses[target].second;
    }

    cout << time << endl;

    return 0;
}
