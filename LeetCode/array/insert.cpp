//
// Created by 34021 on 2025/9/3.
//

#include <vector>
#include<iostream>
using namespace std;
long long searchInsert(vector<long long>& nums, long long target) {
        long long low = 0;
        long long high = nums.size() - 1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (nums[mid] == target)return mid;
            else if (nums[mid] < target)low = mid + 1;
            else high = mid - 1;
        }
        return low;
}
long long main() {
    vector<long long> nums = {5,7,7,8,8,10};
    long long target = 8;
    cout << searchInsert(nums,target) << endl;
    return 0;
}
