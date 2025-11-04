#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        string t = s.substr(0, n-2);
        string o = t + "i";
        cout << o << "\n";
    }
}
