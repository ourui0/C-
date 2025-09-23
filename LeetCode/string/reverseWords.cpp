//
// Created by 34021 on 2025/9/23.
//
#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    string ans;
    int slow = s.size();
    for (int i = s.size() - 1;i >= 0;i--) {
        if (s[i] == ' ') {
            if (i > 0 && isalpha(s[i + 1])) {
                for (int j = i + 1;j < slow;j++) {
                    if (s[j] != ' ')ans.push_back(s[j]);
                }
                ans.push_back(' ');
            }
            slow = i;
        }
    }
    for (int i = 0;i < slow;i++) {
        ans.push_back(s[i]);
    }
    return ans;
}
int main() {
    string s = "  hello world  ";
    s=reverseWords(s);
    cout<<s;
    return 0;
}