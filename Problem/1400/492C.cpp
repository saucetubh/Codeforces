#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, r, avg;
    cin >> n >> r >> avg;
    vector<pair<long, long>> e(n);
    long long sum=0;
    long long essay = 0;
    for(int i=0;i<n;i++) {
        long long a, b;
        cin >> a >> b;
        e[i] = {b, a};
        sum=sum+a;
    }
    sort(e.begin(), e.end());
    long long goal = avg*n;
    int i=0;
    while(sum<goal) {
        long long need = goal - sum;
        long long can = r - e[i].second;
        long long take = min(need, can);
        essay+=(e[i].first*take);
        sum+=take;
        i++;
    }
    cout << essay << endl;
}