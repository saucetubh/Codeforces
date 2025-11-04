#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == s[i+1]) {
                n=1;
                break;
            }
        }
        cout << n << "\n";
    }
}