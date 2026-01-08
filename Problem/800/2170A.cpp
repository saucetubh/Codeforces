#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n==1) {
        cout << 1 << endl;
        return;
    }
    if(n==2) {
        cout << 9 << endl;
        return;
    }
    if(n==3 || n==4) {
        cout << (4*n*n)-n-4 << endl;
        return;
    }
    else {
        cout << 5*((n*n)-n-1) << endl;
    }
}


int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}