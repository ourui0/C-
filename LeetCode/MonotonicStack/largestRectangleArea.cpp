//
// Created by 34021 on 2025/9/18.
//
#include<iostream>
#include <stack>
#include<vector>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<pair<int,int>> st;//第二位表示如果栈空。加入的下一个元素要加上之前栈的长度
    int ans = 0;
    int Area = 0;//计算矩形面积
    int num = 0;//记录因为他被推出的数
    st.emplace(0,0);
    for(int i=1;i<heights.size();i++) {
        num = 0;
        while(!st.empty() && heights[st.top().first] > heights[i]) {
            Area = heights[st.top().first] * (i + st.top().second - st.top().first);
            if(Area > ans) {
                ans = Area;
            }
            num += st.top().second + 1;
            st.pop();
        }
        st.emplace(i,num);
    }
    while(!st.empty()) {//如果到底没有遇到更小的值
        Area = heights[st.top().first] * (heights.size() + st.top().second - st.top().first);
        if(Area > ans) {
            ans = Area;
        }
        st.pop();
    }
    return ans;
}
int main() {
    vector<int> heights = {3,2,1,3,2,1};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}