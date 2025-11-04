#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int r = x % 10;
        int n;
        if(x>0 && x<10) {
            n=1;
        }
        else if (x>10 && x<100) {
            n=2;
        }
        else if (x>100 && x<1000) {
            n=3;
        }
        else if (x>1000 && x<10000) {
            n=4;
        }
        int a;
        switch(n) {
            case 1:
                a = 10*(r-1) + 1;
                break;
            case 2:
                a = 10*(r-1) + 3;
                break;
            case 3:
                a = 10*(r-1) + 6;
                break;
            case 4:
                a = 10*(r-1) + 10;
                break;
        }
        cout << a << endl;
    }
}