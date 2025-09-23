//
// Created by 34021 on 2025/9/21.
//
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> set;
    for(int i=0;i<nums.size();i++) {
        if (set.find(target - nums[i]) != set.end()) {
            return vector<int>{set[target-nums[i]],i};
        }
        set.insert({nums[i],i});
    }
}
int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}