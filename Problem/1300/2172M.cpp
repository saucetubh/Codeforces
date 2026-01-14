#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n,m,k; cin >> n >> m >> k;
    int a[200000]; 
    vector<int> ans(k);
    for(int i=0;i<n;i++) {
        cin >> a[n];
    }
    pair<int, int> road[200000];
    for(int i=0;i<m;i++) {
        cin >> road[i].first >> road[i].second;
    }
     
    //do it



    for(int i=0;i<k;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}