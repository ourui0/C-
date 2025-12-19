//
// Created by 34021 on 2025/12/17.
//
#include<bits/stdc++.h>
using namespace std;
int candy(vector<int>& ratings) {
    int len = ratings.size();
    if (len == 1)return 1;
    stack<int> st;
    vector<int> min_candy(len,1);
    st.push(0);
    for (int i = 1;i < len ;i++) {
        if (ratings[st.top()] < ratings[i]) {
            min_candy[i] = min_candy[st.top()] + 1;
            while (!st.empty()) {
                int top = st.top();
                st.pop();
                if (st.empty())break;
                if (ratings[st.top()] != ratings[top]) {
                    min_candy[st.top()] = max(min_candy[st.top()],min_candy[top] + 1);
                }
            }
        }
        st.push(i);
    }
    //处理栈内元素
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (st.empty())break;
        if (ratings[st.top()] != ratings[top]) {
            min_candy[st.top()] = max(min_candy[st.top()],min_candy[top] + 1);
        }
    }
    int ans = 0;
    for (int i = 0;i < len;i++) {
        ans += min_candy[i];
    }
    return ans;
}
int main() {
    vector<int> nums = {1,3,2,2,1};
    cout << candy(nums);
}