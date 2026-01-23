#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    int ans=0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<m;i++) {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ap=0;
    int bp=0;
    while(ap<n && bp<m) {
        if(a[ap] <= b[bp]+k && a[ap] >= b[bp]-k) {
            ap++; bp++; ans++;
        }
        else if(a[ap] > b[bp]+k) {
            bp++;
        }
        else {
            ap++;
        }
    }
    cout << ans << endl;
    /*
    for(int i=0;i<b.size();i++) {
        for(int j=0;j<a.size();j++) {
            if(a[j] <= b[i]+k && a[j] >= b[i]-k) {
                ans++;
                a.erase(a.begin()+j);
            }
        }
    }
    */
    //trivial inefficient solution
}

/*
start from smallest b, check from smallest a onwards if b +- k == a, loop and repeat -> O(n2), inefficient

4 3 5
45 60 60 80
30 60 75

use two pointers ap and bp, move bp if ai>bi and move ap if bi>ai till ai and bi within desired range, if desired range found then do ap++ and bp++ -> repeat
*/
