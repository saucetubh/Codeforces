#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long; 
/*
void solve() {
    ll w,h,d;
    cin >> w >> h >> d;
    ll n;
    cin >> n;
    //find w1, h1, d1 such that nw1h1d1=whd
    ll v = w * h * d;
    if(v%n) {
        cout << -1;
        return;
    }
    else {
        ll vs = v/n;
        //brute force, time complexity = O(w*h*d) , very inefficient for larger inputs
        for(ll wi=1;wi<=w;wi++) {
            for(ll hi=1;hi<=h;hi++) {
                for(ll di=1;di<=d;di++) {
                    if(wi*hi*di == vs && w%wi == 0 && h%hi == 0 && d%di == 0) {
                        cout << (w/wi)-1 << " " << (h/hi)-1 << " " << (d/di)-1 << endl;
                        return;
                    }
                }
            }
        }
    }
} //Inefficeint approach
*/ 
void solve() {
    ll w, h, d;
    cin >> w >> h >> d;
    ll n;
    cin >> n;
    ll a = gcd(n,w);
    n = n/a;
    ll b = gcd(n,h);
    n = n/b;
    ll c = n;
    if(d%c != 0) {
        cout << -1 << endl;
        return;
    }
    else {
        cout << a-1 << " " << b-1 << " " << c-1 << endl;
    }
}

int main() {
    solve();
    return 0;
}