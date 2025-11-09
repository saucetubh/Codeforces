#include <iostream>
using namespace std;

int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int sum = 0;
    int m = min(k2, min(k5, k6));
    sum = sum + (m*256);
    k2 = k2 - m;
    int m1 = min(k2, k3);
    sum = sum + (m1*32);
    cout << sum << endl;
}