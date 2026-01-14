#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n==2) cout << 2 << endl;
    else if(n==3) cout << 3 << endl;
    else {
        cout << n%2 << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}