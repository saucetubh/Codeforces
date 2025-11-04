#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int distinct_count = 0;
        int freq[101] = {0};
        for(int i=0;i<n;i++) {
            cin >> a[i];
            if(freq[a[i]] == 0) {
                distinct_count++;
                freq[a[i]] = 1;
            }
        }
        cout << (2*(distinct_count) - 1) << endl;
    }
}

