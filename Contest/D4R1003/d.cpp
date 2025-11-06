#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        while (m--) {
            int sum = 0;
            vector<int> a(m);
            for(int i = 0; i < m; i++) {
                cin >> a[i];
                sum += a[i];
                //implement how i can arrange arrays in decreasing order of sum
            }
        }

    }
}