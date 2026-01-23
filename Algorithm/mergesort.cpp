#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums, int l, int m, int r) {
    int n1=m-l+1;
    int n2=r-m;
    vector<int> Left(n1); 
    vector<int> Right(n2); 
    //copy(nums.begin()+l, nums.begin()+m+1, Left.begin());
    //copy(nums.begin()+m+1, nums.begin()+r+1, Right.begin());
    for(int i=0; i<n1; i++){
        Left[i]=nums[l+i];
    }
    for(int i=0; i<n2; i++){
        Right[i]=nums[m+1+i];
    }
    int lp=0; int rp=0;
    int i=l;
    while(lp<n1 && rp<n2) {
        if(Left[lp]>Right[rp]) {
            nums[i++]=Right[rp++];
        }
        else {
            nums[i++]=Left[lp++];
        }
    }
    while(rp<n2) {
        nums[i++]=Right[rp++];
    }
    while(lp<n1) {
        nums[i++]=Left[lp++];
    }
}

void mergesort(vector<int>& nums, int l, int r) {
    if(l>=r) return;
    int m=(l+r)/2;
    mergesort(nums, l, m);
    mergesort(nums, m+1, r);
    merge(nums, l, m, r);
}

int main() {
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    mergesort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}