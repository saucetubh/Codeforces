#include<bits/stdc++.h>
using namespace std;

void calc_sums(vector<int>& a, vector<long long int>& sums, int low, int high) {
    int m = (low+high)/2;
    if(low<high) {
        long long int sum = 0;
        for(int i=low;i<=high;i++) {
            sum += a[i];
        }
        sums.push_back(sum);
        calc_sums(a, sums, low, m);
        calc_sums(a, sums, m+1, high);
    }
    else {
        sums.push_back(a[low]);
        return;
    }
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
        calc_sums(a, sums, 0, n-1);
        sort(sums.begin(),sums.end());
        for(auto i : sums) {
            cout << i << " ";
        }
    }
}