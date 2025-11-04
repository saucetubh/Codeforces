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
        int b;
        cin >> b;
        bool flag = true;
        A[0] = min(A[0], b - A[0]);
        for(int i=1;i<n;i++) {
            int t1=min(A[i], b - A[i]);
            int t2=max(A[i], b - A[i]);
            if(A[i-1] <= t1) {
                A[i] = t1;
            }
            else if(A[i-1] > t2) {
                flag = false;
                break;
            }
            else {
                A[i] = t2;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}