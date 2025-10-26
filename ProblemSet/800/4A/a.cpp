#include <bits/stdc++.h>
using namespace std;

int main() {
    int w;
    cin >> w;
    if(w > 2 && w%2 == 0) cout << "YES";
    else cout << "NO";
}

//pretty simple, just need to check if an integer can be split into two even integers
//we know even + even = even
//also need to check for border case w = 2