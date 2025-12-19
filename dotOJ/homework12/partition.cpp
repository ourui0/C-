//
// Created by 34021 on 2025/12/15.
//
#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int> &nums,int cnt) {
    int n = nums.size();
    int target = cnt / 2;
    vector<bool> dp(target + 1,false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        // 倒序更新，避免重复使用同一数字
        for (int j = target; j >= nums[i]; j--) {
            if (dp[j - nums[i]]) {
                dp[j] = true;
            }
        }
    }

    return dp[target];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    int num;
    int cnt = 0;
    while (cin >> num) {
        nums.emplace_back(num);
        cnt+=num;
    }

    if (cnt % 2 !=0||!canPartition(nums,cnt)) {
        cout << 0;
    }
    else {
        cout << 1;
    }
    return 0;
}