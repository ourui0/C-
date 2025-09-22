//
// Created by 34021 on 2025/9/22.
//
#include<bits/stdc++.h>
using  namespace std;
string reverseStr(string s, int k) {
    int n = s.length();
    for (int i = 0,j = k - 1; i < n; i+=2 * k,j += 2 * k) {
        if (n - i < k) {
            j = n - 1;
            while (i < j) {
                swap(s[i++],s[j--]);
            }
            break;
        }
        int I = i,J = j;
        while (I < J) {
            swap(s[I++],s[J--]);
        }
    }
    return s;
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    s = reverseStr(s,k);
    cout<<s;
    return 0;
}