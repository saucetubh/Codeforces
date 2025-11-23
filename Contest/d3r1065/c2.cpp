#include <bits/stdc++.h>
using namespace std;
void solve() {
int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for (int k = 20; k >= 0; --k) {
        int c = 0;
        int d = -1;
        for (int i = 0; i < n; ++i) {
            int bit_a = (a[i] >> k) & 1;
            int bit_b = (b[i] >> k) & 1;
            if (bit_a != bit_b) {
                c++;
                d = i + 1; 
            }
        }
        if (c % 2 != 0) {
            if (d % 2 != 0) {
                cout << "Ajisai" << endl;
            } 
            else {
                cout << "Mai" << endl;
            }
            return;
        }
    }
    cout << "Tie" << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}