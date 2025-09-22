//
// Created by 34021 on 2025/9/13.
//
#include<iostream>
#include<vector>
using namespace std;

//解法一：滑动窗口
int minSubArrayLen(int target, vector<int>& nums) {
    int min = INT_MAX;
    int left = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += nums[i];
        while(count >= target) {
            if (i - left + 1< min)min = i - left + 1;
            count -= nums[left];
            left++;
        }
    }
    return min == INT_MAX ? 0 : min;
}
//解法二：二分查找
int minSubArrayLen2(int target, vector<int>& nums) {
    vector<int> prefix(nums.size() + 1);//前缀和数组
    prefix[0] = 0;
    for (int i = 1; i <= nums.size(); i++) {
        prefix[i] = nums[i - 1] + prefix[i - 1];
    }
    int min = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        int sum = prefix[i] + target;
        auto it = lower_bound(prefix.begin() + i + 1, prefix.end(), sum);
        if (it != prefix.end()) {
            int index = it - prefix.begin();
            int current_length = index - i;
            if (current_length < min)min = current_length;
        }
    }
    return min == INT_MAX ? 0 : min;
}
int main() {
    int t = 15;
    vector<int> nums = {1,2,3,4,5};
    cout << minSubArrayLen2(t, nums) << endl;
    return 0;
}