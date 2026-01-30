#include<bits/stdc++.h>
using namespace std;

void calc_sums(vector<int>& a, vector<long long int>& sums, int l, int h) {
    if(l>=h) {
        sums.push_back(a[l]);
        return;
    }
    int mid = (a[l]+a[h])/2;
    int m=-1;
    long long int sum=0;
    for(int i=l;i<=h;i++) {
        if(a[i]<=mid) {
            m=i;
        }
        sum+=a[i];
    }
    sums.push_back(sum);
    if(m>=h) return;
    calc_sums(a,sums,l,m);
    calc_sums(a,sums,m+1,h);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; int q; cin >> n >> q;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        vector<int> s(q);
        for(int i=0;i<q;i++) {
            cin >> s[i];
        }
        vector<long long int> sums;
        sort(a.begin(), a.end());
        calc_sums(a, sums,0,n-1);
        sort(sums.begin(),sums.end());
        for(int i=0;i<q;i++) {
            if(binary_search(sums.begin(),sums.end(),s[i])) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}