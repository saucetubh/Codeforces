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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }  
        vector<int> sa(n); 
        sort(sa.begin(), sa.end());
        for(int i=0;i<n;i++) {
            vector<int> b(n);
            b[0]=a[i];
            //finish
        }
    }
    
}