//
// Created by 34021 on 2025/9/9.
//
#include<iostream>
using namespace std;

string s = "";//标记为全局变量方便修改
bool isSame(int n,int i) {
    int count1 = 0,count2 = 0;//计种类
    for (int j = i; j <= i + n; j++) {
        if (isdigit(s.at(j))) {
            count1 = 1;
        }
        if (isalpha(s.at(j))) {
            count2 = 1;
        }
        if (count1 == count2 && count1 == 1) {
            return false;
        }
    }
    return true;
}
void transform(int n) {
    if (n == 0) {
        s = "INVALID";
        return;
    }
    int length = s.length();
    for (int i = 0; i < length; i++) {
        if (s.at(i) == '-') {
            s.erase(i,1);
            length--;
        }
        if (s.at(i) >= 'a'&&s.at(i) <= 'z') {
            s.at(i) = s.at(i) - 32;
        }
    }
    int idx = 1;//表示组下标
    for (int i = 0; i < s.length() - n;) {
        if (idx!=n) {
            if (!isSame(n,i)) {
                s.insert(i + n,"-");
                idx++;
                i+=n + 1;
            }
            else {
                s = "INVALID";
                return;
            }
        }
        else {
            idx++;
            int index = 0;
            for (int j = 1; j <= n; j++) {
                if ((s.length()-i-j) %n == 0) {
                    index = 1;
                    s.insert(i + j,"-");
                    i+=j+1;
                    break;
                }
            }
            if (index != 1) {
                s = "INVALID";
                return;
            }
        }
    }
    if (idx != n) {
        if (isSame(n,s.length() - n - 1)) {
            s = "INVALID";
            return;
        }
    }
    if (idx < n) {
        s = "INVALID";
    }
}
int main() {
    cin >> s;
    int n;
    cin >> n;
    transform(n);
    cout << s;
    return 0;
}