#include<bits/stdc++.h>
using namespace std;
int main() { 
    long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long answer = -1; 
        for (long long p : primes) {
            bool all_divisible = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] % p != 0) {
                    all_divisible = false;
                    break; 
                }
            }
            if (!all_divisible) {
                answer = p;
                break; 
            }
        }
        cout << answer << "\n";
    }
}