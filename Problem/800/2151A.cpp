#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        bool s = true;
        int max = 0;
        for(int i=0;i<m;i++) {
            cin >> a[i];
            if(max < a[i]) {
                max = a[i];
            }
            else {
                s = false;
                break;
            }
        }
        if(s) {
            cout << 5-(n-1) << endl;
        }
        else {
            //implement
        }
    }
}