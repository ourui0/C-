//
// Created by 34021 on 2025/9/21.
//
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    vector<int> res;
    for(int i=0; i<nums1.size(); i++) {
       mp[nums1[i]]++;
    }
    for(int i=0; i<nums2.size(); i++) {
        if(mp[nums2[i]]>0) {
            mp[nums2[i]] = 0;
            res.push_back(nums2[i]);
        }
    }
    return res;
}
int main() {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {1,2,3,4};
    vector<int> result = intersection(nums1,nums2);
    for(int i=0;i<result.size();i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}