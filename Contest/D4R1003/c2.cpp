#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);
        for(int i=0;i<n;i++) cin >> A[i];
        vector<int> B(m);
        for(int i=0;i<m;i++) cin >> B[i];
        bool flag = true;
        //implement
        cout << (flag ? "YES\n" : "NO\n");
    }
}