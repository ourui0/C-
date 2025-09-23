//
// Created by 34021 on 2025/9/23.
//
#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    string ans;
    int slow = s.length();
    int pos = 0;//去除数组前的空格
    while (s[pos] == ' ') {
        pos++;
    }
    for (int i = slow - 1;i >=pos ;i--) {
        if ((i > 0&&s[i - 1] == ' '&& s[i] != ' ')||i==pos) {
            for (int j = i;j < slow;j++) {
                if (s[j]!=' ') {
                    ans.push_back(s[j]);
                }
            }
            if (i!=pos)ans.push_back(' ');
            slow = i;
        }
    }
    return ans;
}
int main() {
    string s = "  hello world  ";
    s = reverseWords(s);
    cout<<s;
    return 0;
}