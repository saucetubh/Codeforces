#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        vector<int> p(n,0);
        for(int i=1;i<n-1;i++) {
            if((a[i-1]<a[i]) && (a[i]>a[i+1])) {
                p[i]=1;
            }
        }
        //complete it
    }
}