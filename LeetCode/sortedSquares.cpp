//
// Created by 34021 on 2025/9/12.
//
#include<iostream>
#include<vector>
using namespace std;

//用双指针法实现数组操作

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res(nums.size());
    int k = nums.size() - 1;
    int left = 0,right = nums.size()-1;
    while (left <=  right) {
        if (nums[left] * nums[left] >= nums[right] * nums[right]) {
            res[k--] = nums[left] * nums[left];
            left++;
        }
        else if (nums[left] * nums[left] < nums[right] * nums[right]) {
            res[k--] = nums[right] * nums[right];
            right--;
        }
    }
    return res;
}

int main() {
    vector<int> nums1 = {-7,-3,2,3,11};
    vector<int> nums2 = sortedSquares(nums1);
    for (int i : nums2) {
        cout<<i<<" ";
    }
    return 0;
}