//
// Created by 34021 on 2025/9/22.
//
#include<bits/stdc++.h>
using namespace std;
//题目很像回溯，但是回溯是一种很乐色的方法，其时间复杂度为O（n^k）,这题目中的k为3，并不是一个较大的数，因此不必要使用回溯

//这道题目实现功能其实并不难，难在如何减少时间复杂度，我们需要找到三个元素的和，而且要保证其并不重复（一种数字只储存一遍）
//并不是计数，我们还需要找到其中的元素，不同元素的和还不同
//结论，使用hash不太妥当
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    // 找出a + b + c = 0
    // a = nums[i], b = nums[left], c = nums[right]
    for (int i = 0; i < nums.size(); i++) {
        // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
        if (nums[i] > 0) {
            return result;
        }
        // 错误去重a方法，将会漏掉-1,-1,2 这种情况
        /*
        if (nums[i] == nums[i + 1]) {
            continue;
        }
        */
        // 正确去重a方法
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (right > left) {
            // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
            /*
            while (right > left && nums[right] == nums[right - 1]) right--;
            while (right > left && nums[left] == nums[left + 1]) left++;
            */
            if (nums[i] + nums[left] + nums[right] > 0) right--;
            else if (nums[i] + nums[left] + nums[right] < 0) left++;
            else {
                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;

                // 找到答案时，双指针同时收缩
                right--;
                left++;
            }
        }

    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}