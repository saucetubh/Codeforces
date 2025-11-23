#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n % 2 != 0) {
        cout << 0 << endl;
    }
    else {
    int valid_configurations = 0;
    for (int c = 0; c * 4 <= n; c++) {
        int lt = c * 4;
        int ll = n - lt;
        if (lt % 2 == 0) {
            valid_configurations++;
        }
    }
    cout << valid_configurations << endl;
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

