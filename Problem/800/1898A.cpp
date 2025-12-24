#include <bits/stdc++.h>
using namespace std;

    void solve() {
        int n,k; cin >> n >> k;
        vector<char> s(n);
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++) {
            cin >> s[i];
            if(s[i] == 'B') {
                b.push_back(i);
            }
            if(s[i] == 'A') {
                a.push_back(i);
            }
        }
        if(k==b.size()) {
            cout << 0 << endl;
            return;
        }
        if(k>b.size()) {
            cout << 1 << endl;
            cout << a[k-b.size()-1] + 1 << " B" << endl;
            return;
        }
        if(k<b.size()) {
            cout << 1 << endl;
            cout << b[b.size()-k-1] + 1 << " A" << endl;
            return;
        }    
    }
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}