//
// Created by 34021 on 2025/12/12.
//
#include<bits/stdc++.h>
using namespace std;
int jump(vector<int>& nums) {
    int len = nums.size();
    int cnt = 0;
    int cur = 0;
    while (true) {
        int max = 0;
        int temp;
        for (int i = 1;i <= nums[cur];i++) {
            if (i + nums[cur + i] > max) {
                temp = i;
                max = i + nums[cur + i];
            }
        }
        cur += temp;
        cnt++;
        if (cur + nums[cur] >= len - 1) {
            cnt++;
            break;
        }
    }
    return cnt;
}
int main() {
    vector<int> nums = {1,2,1,1,1};
    cout << jump(nums);
    return 0;
}