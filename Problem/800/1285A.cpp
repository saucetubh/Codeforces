#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> s(n);
    int cl=0;
    int cr=0;
    for(int i=0;i<n;i++) {
        cin >> s[i];
        if(s[i]=='L') {
            cl++;
        }
        if(s[i]=='R') {
            cr++;
        }
        else {
            continue;
        }
    }
    cout << (cr+cl+1) << endl;

}