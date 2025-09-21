//
// Created by 34021 on 2025/9/21.
//
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    /*对于四个数组，暴力解法很容易知道是O（n^4），我们将其中一个储存在hashmap中，很容易知道变为了O（n^3），那么，能不能更快
    对于这题我们关注的其实并不是每个数组有什么，而是这几个数组的和有什么，因此我们可以将这四个数组分成两份，分别储存两个数组的和，
    这样我们就可以将复杂度缩到O（n^2）*/

    unordered_map<int,int> map;
    int n = nums1.size();
    for(int i : nums1) {
        for(int j : nums2) {
            map[i + j]++;
        }
    }
    int ans = 0;
    for (int i : nums3) {
        for (int j : nums4) {
            if (map.find(-i - j) != map.end()) {
                ans += map[-i - j];
            }
        }
    }
    return ans;
}
int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    cout << fourSumCount(nums1, nums2, nums3, nums4);
    return 0;
}