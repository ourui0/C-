//
// Created by 34021 on 2025/9/21.
//
#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<int,int> map;
    if (ransomNote.size() > magazine.size()) {
        return false;
    }
    for(int i : magazine) {
        map[i]++;
    }
    for(int i : ransomNote) {
        if(map[i] == 0) {
            return false;
        }
        map[i]--;
    }
    return true;
}

int main() {
    string ransomNote = "hello";
    string magazine = "hole";
    cout << canConstruct(ransomNote, magazine) << endl;
    return 0;
}