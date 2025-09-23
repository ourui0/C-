//
// Created by 34021 on 2025/9/22.
//
#include<bits/stdc++.h>
using namespace std;
void reverseString(string &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}
int main() {
    string s;
    cin>>s;
    reverseString(s);
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
    }
    return 0;
}