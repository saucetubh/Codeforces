#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int i=0;
    long long running_sum = 0;
    while(k--) {
        if(i>=n) {
            cout << 0 << endl;
            continue;
        }
        long long x = a[i] - running_sum;
        if(x>0) {
            cout << x << endl;
            running_sum += x;
        }
        else {
            if(i<n-1) {
                i++;k++;
                continue;
            }
            else {
                cout << 0 << endl;
            }
        }
        i++;
    }
}