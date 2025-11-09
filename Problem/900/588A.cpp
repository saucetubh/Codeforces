#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(n);
    int m = 1000;
    int cost=0;
    for(int i=0;i<n;i++) {
        cin >> a[i] >> p[i];
    }
    for(int i=0; i<n; i++) {
        if(p[i] <= min(m, p[i])) {
            m = min(m,p[i]);
        }
        cost = cost + (a[i]*m);
    }
    cout << cost << endl;
}

//keeps track of the running minimum (global minimum will not give correct answer always)
//can this be optimised?