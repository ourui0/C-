//
// Created by 34021 on 2025/9/21.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> m;
    int n = s.length(),v = t.length();
    if (n!=v) return false;
    for (int i = 0; i < n; i++) {
        m[s[i]]++;
        m[t[i]]--;
    }
    for(const auto& a:m){
        if(a.second!=0) return false;
    }
    return true;
}
int main() {
    string s, t;
    cin >> s >> t;
    cout << isAnagram(s, t) << endl;
}