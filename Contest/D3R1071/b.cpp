#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long total_sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_sum += abs(a[i] - a[i + 1]);
    }
    long long min_time = total_sum;
    long long cost_without_first = total_sum - abs(a[0] - a[1]);
    min_time = min(min_time, cost_without_first);
    long long cost_without_last = total_sum - abs(a[n - 2] - a[n - 1]);
    min_time = min(min_time, cost_without_last);
    for (int i = 1; i < n - 1; ++i) {
        long long old_segment = abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]);
        long long new_segment = abs(a[i - 1] - a[i + 1]);
        long long current_cost = total_sum - old_segment + new_segment;
        min_time = min(min_time, current_cost);
    }
    cout << min_time << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


//redo it