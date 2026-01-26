#include <bits/stdc++.h>
using namespace std;

int partitionIndex(vector<int>& nums, int low, int high) {
    int p=low;
    int i=low;
    int j=high;
    while(i<j) {
        while(nums[i]<=nums[p] && i<high) i++;
        while(nums[j]>=nums[p] && j>low) j--;
        if(i<j) swap(nums[i],nums[j]);
        else swap(nums[j],nums[p]);
    }
    return j;
}

void quicksort(vector<int>& nums, int low, int high) {
    if(low>=high) return;
    int p = partitionIndex(nums, low, high);
    quicksort(nums, low, p-1);
    quicksort(nums, p+1, high);
}

int main() {
    vector<int> nums = {5,6,1,2,4,3}; // Example input
    quicksort(nums, 0, nums.size()-1);
    for(int c : nums) {
        cout << c << " ";
    }
}