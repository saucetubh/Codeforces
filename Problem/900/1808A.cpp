#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int maxluck=0;
    int num=l;
    for(int i=l; i<=min(r,l+100); i++) {
        int max=0;
        int min=9;
        int j=i;
        while(j>0) {
            if((j%10)>max) {
                max = j%10;
            }
            if((j%10)<min) {
                min = j%10;
            }
            j=j/10;
        }
        if((max - min)>maxluck) {
            maxluck=max-min;
            num=i;
        }
    }
    cout << num << endl;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}