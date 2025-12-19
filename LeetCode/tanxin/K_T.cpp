//
// Created by 34021 on 2025/12/17.
//

#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &a,const int &b) {
    return abs(a) > abs(b);
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end(),cmp);
    for (int &num : nums) {
        if (num < 0 && k > 0) {
            num = -num;
            k--;
        }
    }
    int l = nums.size();
    if (k > 0&&k % 2 != 0) {
        nums[l - 1] = -nums[l - 1];
    }
    int ans = 0;
    for (int I : nums) {
        ans += I;
    }
    return ans;
}
int main() {
    int k = 1;
    vector<int> nums = {4,2,3};
    cout << largestSumAfterKNegations(nums,k);
    return 0;
}