#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n < 6) {
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << endl;
        return;
    }
    vector<int> evens;
    vector<int> mult3; 
    vector<int> others; 
    for (int i = 1; i <= n; ++i) {
        if (i == 6) continue; 
        if (i % 2 == 0) {
            evens.push_back(i);
        } 
        else if (i % 3 == 0) {
            mult3.push_back(i);
        } 
        else {
            others.push_back(i);
        }
    }
    vector<int> result;
    int o = 0;
    int e = 0;
    while (e + 1 < evens.size() && o < others.size()) {
        result.push_back(evens[e++]);
        result.push_back(evens[e++]);
        result.push_back(others[o++]);
    }
    while (e < evens.size()) {
        result.push_back(evens[e++]);
    }
    result.push_back(6);
    int m = 0;
    while (m + 1 < mult3.size() && o < others.size()) {
        result.push_back(mult3[m++]);
        result.push_back(mult3[m++]);
        result.push_back(others[o++]);
    }
    while (m < mult3.size()) {
        result.push_back(mult3[m++]);
    }
    while (o < others.size()) {
        result.push_back(others[o++]);
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}