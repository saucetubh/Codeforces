#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> out;
void op1(const vector<int>& a, vector<int>& s, int l, int r) {
    l--; r--;
    for(int i=l; i<=r; i++) {
        s[i]=s[i]^1;
    }
}

void op2(const vector<int>& a, vector<int>& s, int g) {
    int res=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]==g) {
            res^=a[i];
        }
    }
    out.push_back(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        out.clear();
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        string str;
        cin >> str;
        vector<int> s(n);
        for(int i=0;i<n;i++) {
            s[i] = str[i]-'0';
        }
        int q; cin >> q;
        while (q--) {
            int tp; cin >> tp;
            if(tp==1) {
                int l, r; cin >> l >> r;
                op1(a, s, l, r);
            }
            if(tp==2) {
                int g; cin >> g;
                op2(a, s, g);
            }
        }
        for(int i=0;i<out.size();i++) {
            cout << out[i] << " ";
        }
        cout << "\n";
    }
}

//fix this, time limit exceeded

