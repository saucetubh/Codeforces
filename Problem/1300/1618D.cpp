#include <bits/stdc++.h>
using namespace std;
/*
void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    long long score=0;
    sort(a.begin(),a.end());
    while(k--) {
        int l=0;
        int r=1;
        int num = a[l];
        while(r<a.size()-1 && a[l]==a[r]) r++;
        int denom = a[r];
        score += num/denom;
        a.erase(a.begin()+r);
        a.erase(a.begin()+l);
    }
    if(a.empty()) {
        cout << score << endl;
        return;
    }
    else {
        for(int i=0;i<a.size();i++) {
            score+=a[i];
        }
        cout << score << endl;
        return;
    }
}
*/

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    long long score = 0;
    sort(a.begin(), a.end());
    for(int i=0;i<(n-(2*k));i++) {
        score+=a[i];
    }
    int l=n-(2*k);
    for(int i=l;i<l+k;i++) {
        score += (a[i]/a[i+k]);
    }
    cout << score << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}


//for every x in num, choose the number just after x that is not x from the sorted array to be denom, add num/denom to score, remove num and denom from array and repeat until k pairs are made
//this method above isnt correct, doesnt always give the correct answer. Try some other approach

/*
Correct approach - 
2k numbers to remove 
sort array
first (n-2k) elements left as it is
last 2k elements paired and removed, pair bi with b(i+k) and so on
*/