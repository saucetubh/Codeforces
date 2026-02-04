#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int,int>> ab(n);
        for(int i=0;i<n;i++) {
            int x,y; cin >> x >> y;
            ab[i]={x,y};
        }
        sort(ab.begin(),ab.end());
        long long ans=0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(ab[i].second>ab[j].second) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

