#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int g,c,l;
    cin >> g >> c >> l;
    vector<int> a = {g,c,l};
    sort(a.begin(), a.end());
    if(a[2]-a[0]>=10) cout << "check again \n";
    else cout << "final " << a[1] << "\n";
}