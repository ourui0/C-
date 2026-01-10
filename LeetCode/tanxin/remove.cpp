//
// Created by 34021 on 2026/1/7.
//
#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string &num, int k) {
    string st;
    int cnt = 0;//记录溢出的数量
    int l = num.size();
    for (int i = 0;i < l;i++) {
        if (!st.empty()) {
            if (st[st.size() - 1] > num[i]) {
                while (!st.empty()&&cnt < k&&st[st.size() - 1] > num[i]) {
                    st.pop_back();
                    cnt++;
                }
                if (num[i] == '0'&&st.empty())continue;
                st.push_back(num[i]);
                continue;
            }
        }
        if (num[i] != '0'||!st.empty())st.push_back(num[i]);
    }
    while(cnt < k&&!st.empty()) {
        st.pop_back();
        cnt++;
    }
    if (st.empty())return "0";
    return st;
}
int main() {
    string nums = "10200";
    int k = 1;
    cout << removeKdigits(nums,k);
}