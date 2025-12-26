#include <iostream>
using namespace std;

void solve() {
    string s; cin >> s;
    int op[] = {0,0,0};
    for(char c:s) {
        switch(c) {
            case '<': op[0]++; break;
            case '>': op[1]++; break;
            case '=': op[2]++; break;
        }
    }
    if((op[0] > 0) && (op[1] > 0)) {
        cout << "?" << endl;
    }
    else if(op[0] > 0 && op[1]==0) {
        cout << "<" << endl;
    }
    else if(op[0]==0 && op[1] > 0) {
        cout << ">" << endl;
    }
    else {
        cout << "=" << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}