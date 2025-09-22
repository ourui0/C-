//
// Created by 34021 on 2025/9/3.
//
#include <vector>
#include<iostream>
using namespace std;
vector<long long> searchRange(vector<long long>& nums, long long target) {
    if(nums.size() == 0)return {-1,-1};
    long long low = 0,high = nums.size() - 1;
    vector<long long> ranger = {};
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (nums[mid] == target) {
            long long count1 = 1,count2 = -1;
            while (true) {
                if (mid + count1 < nums.size()&&nums[mid+count1] == target) {
                    count1++;
                }
                else if (mid + count2 > -1&&nums[mid+count2] == target) {
                    count2--;
                }
                if (((mid + count1 <  nums.size()&&nums[mid+count1] != target)||mid + count1 >=  nums.size())&&((mid + count2 > -1&& nums[mid+count2] != target)||mid + count2 <= -1)) {
                    ranger.push_back(mid+count2+1);
                    ranger.push_back(mid+count1 - 1);
                    return ranger;
                }
            }
        }
        else if (nums[mid] < target)low = mid + 1;
        else high = mid - 1;
    }
    if (low > high)return {-1,-1};
    return {};
}
long long main() {
    vector<long long> nums = {2,2};
    long long target = 2;
    vector<long long> answer = searchRange(nums,target);
    long long length = answer.size();
    for (long long i = 0; i < length; i++) {
        cout << answer[i] << " ";
    }
    return 0;
}