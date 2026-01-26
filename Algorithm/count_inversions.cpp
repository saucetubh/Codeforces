#include <bits/stdc++.h>
using namespace std;

long long int inv_count = 0;
    void merge(vector<int>& nums, int l, int m, int r) {
        int n1=m-l+1;
        int n2=r-m;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=0;i<n1;i++) {
            left[i]=nums[l+i];
        }
        for(int i=0;i<n2;i++) {
            right[i]=nums[m+1+i];
        }
        int lp=0;
        int rp=0;
        int i=l;
        while(lp<n1 && rp<n2) {
            if(left[lp]<=right[rp]) {
                nums[i++]=left[lp++];
            }
            else {
                inv_count=inv_count+n1-lp;
                nums[i++]=right[rp++];
            }
        }
        while(lp<n1) {
            nums[i++]=left[lp++];
        }
        while(rp<n2) {
            nums[i++]=right[rp++];
        }
    }
    void mergesort(vector<int>& nums, int l, int r) {
        if(l>=r) return;
        int m = (l+r)/2;
        mergesort(nums,l,m);
        mergesort(nums,m+1,r);
        merge(nums, l, m, r);
    }
    void numberOfInversions(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
    }

    int main() {
    vector<int> nums = {2, 3, 8, 6, 1}; //expected output 5
    numberOfInversions(nums);
    cout << inv_count << endl;
}