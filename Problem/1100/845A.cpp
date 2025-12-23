#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int i=0;i<(2*n);i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    /*
    for(int i=n;i<(2*n);i++) {
        if(a[n-1]==a[i]) {
            cout << "No\n";
            return 0;
        }
        else {
            continue;
        }
    }
    cout << "Yes\n";
    */
   if(a[n-1]<a[n]) cout << "Yes\n";
   else cout << "No\n";
}