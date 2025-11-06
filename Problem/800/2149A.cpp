#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int count = 0;
        int flag = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                count++;
            }
            if (a[i] == -1) {
                flag++;
            }
        }  
        if(flag%2 != 0) {
            count = count + 2;
        }
        cout << count << endl;
    }
}