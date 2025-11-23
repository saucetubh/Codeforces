#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int mn = n + 1; 
    for (int i = 0; i < n - 1; ++i) {
        mn = min(mn, p[i]);
        if (mn == n - i) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}