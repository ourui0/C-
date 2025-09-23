//
// Created by 34021 on 2025/9/17.
//
#include<iostream>
#include <stack>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    stack<int> st;
    st.push(0);
    int ans = 0;
    for (int i = 1; i < height.size(); i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            int index = st.top();
            st.pop();
            if (!st.empty()) {
                ans += (min(height[i], height[st.top()]) - height[index]) * (i - st.top() - 1);
            }
        }
        st.push(i);
    }
    return ans;
}
int main() {
    vector<int> nums = {4,2,0,3,2,5};
    cout<<trap(nums)<<endl;
    return 0;
}