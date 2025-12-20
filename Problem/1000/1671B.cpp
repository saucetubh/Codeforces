#include <bits/stdc++.h>
using namespace std;
string solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    int c3=0;
    int c2=0;
    bool flag=true;
    for(int i=1;i<n;i++) {
        cin >> a[i];
        if((a[i]-a[i-1]) > 3) {
            flag=false; //dont break the loop here, otherwise it doesnt read all inputs and ends up assigning wrong inputs to next test cases
        }
        if((a[i]-a[i-1]) == 3) c3++;
        if((a[i]-a[i-1]) == 2) c2++;
    }
    if(!flag) return "NO";
    if(c3==1 && c2==0) return "YES";
    if(c3==0 && c2<=2) return "YES";
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
}