#include <bits/stdc++.h>
using namespace std;
    int merge(vector<int>& nums, int l, int m, int r) {
        int inv_count=0;
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
        return inv_count;
    }
    int mergesort(vector<int>& nums, int l, int r) {
        int inv_count = 0;
        if(l>=r) return inv_count;
        int m = (l+r)/2;
        inv_count+=mergesort(nums,l,m);
        inv_count+=mergesort(nums,m+1,r);
        inv_count+=merge(nums, l, m, r);
        return inv_count;
    }
    int numberOfInversions(vector<int>& nums) {
        int inv_count = mergesort(nums, 0, nums.size()-1);
        return inv_count;
    }
    int main() {
    vector<int> nums = {2, 3, 8, 6, 1}; //expected output 5
    int inv_count = numberOfInversions(nums);
    cout << inv_count << endl;
}