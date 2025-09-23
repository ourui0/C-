//
// Created by 34021 on 2025/9/17.
//
#include<iostream>
#include <stack>
#include <unordered_map>
#include<vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums1, vector<int>& nums2) {
    //我们现在已经可以很轻松的得到nums2中的每个元素的下一个更大元素，因此，我们可以使用单调栈的到下一个更大元素，然后
    //查询结果是否在哈希表里（提前将nums1储存）
    vector<int> res(nums1.size(),-1);
    unordered_map<int,int> mp;
    for(int i=0;i<nums1.size();i++) {
        mp[nums1[i]] = i;
    }
    stack<int> s;
    s.push(0);
    for(int i=0;i<nums2.size();i++) {
        while(!s.empty() && nums2[s.top()]<nums2[i]) {
            if (mp.contains(nums2[s.top()])) {
                res[mp[nums2[s.top()]]] = nums2[i];
            }
            s.pop();
        }
        s.push(i);
    }
    return res;
}
int main() {
    vector nums1 = {4,1,2};
    vector nums2 = {1,3,4,2};
    vector<int> result = nextGreaterElements(nums1,nums2);
    for(int i=0;i<result.size();i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}