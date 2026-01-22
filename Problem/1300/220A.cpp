#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    copy(a,a+n,b.begin());
    sort(b.begin(),b.end());
    int count=0;
    for(int i=0;i<n;i++) {
        if(a[i]!=b[i]) count++;
        if(count > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

