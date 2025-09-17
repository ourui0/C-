//
// Created by 34021 on 2025/9/17.
//
#include<iostream>
#include <stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n,-1);
    stack<int> s;
    s.push(0);
    int count = 0;
    for(int i = 1;i<n;i++) {
        while(!s.empty() && nums[s.top()] < nums[i]) {
            res[s.top()] = nums[i];
            s.pop();
        }
        if (res[i] == -1) {
            s.push(i);
        }
        if (i == n - 1) {
            i = -1;
            count++;
        }
        if (count == 2) {
            break;
        }
    }
    return res;
}

int main() {
    vector nums = {1,2,3,4,3};
    vector<int> result = nextGreaterElements(nums);
    for(int i : result) cout<<i<<" ";
    return 0;
}