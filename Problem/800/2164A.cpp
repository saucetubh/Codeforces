#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        int x;
        cin >> x;
        sort(a.begin(), a.end());
        if(x<=a[n-1] && x>=a[0]) cout << "YES \n";
        else cout << "NO \n";
    }
}