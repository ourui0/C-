//
// Created by 34021 on 2025/9/22.
//
#include<bits/stdc++.h>
using namespace std;
void replaceNum(string &s) {
    for (int i = 0; i < s.size();i++) {
        if (s[i] >= '0' &&s[i] <='9') {
            s[i] = 'r';
            s.insert(i,"numbe");
            i += 5;
        }
    }
}
int main() {
    string s;
    cin>>s;
    replaceNum(s);
    cout<<s;
    return 0;
}