#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    int k = 0;
    int d = -1;
    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            k++;
            d = i + 1; 
        }
    }
    if (k % 2 == 0) {
        cout << "Tie" << endl;
    } 
    else {
        if (d % 2 != 0) { 
            cout << "Ajisai" << endl;
        } 
        else { 
            cout << "Mai" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}