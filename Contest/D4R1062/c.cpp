#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool e = false;
        bool o = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 == 0) e = true;
            if(a[i] % 2 == 1) o = true;
        }
        if(e && o) {
            sort(a.begin(), a.end());
        }
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}