//
// Created by 34021 on 2025/9/9.
//
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (fastIndex != nums.size() - 1) {
            if (nums[fastIndex] != nums[fastIndex + 1]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        else {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    
    return slowIndex;
}
int main() {
    vector<int> nums = {1,1,2,2};
    cout << removeDuplicates(nums) << endl;
    return 0;
}
