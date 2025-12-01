//
// Created by 34021 on 2025/10/10.
//
#include<bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main() {
    int n;
    unsigned seed;
    cin>>n>>seed;

    mt19937 mt(seed);

    vector<ui> nums(100000,0);
    for (int i = 0; i < n; i++) {
        unsigned x = mt() % 100000;
        nums[x]++;
    }

    // 计算哈希值
    long long hash = 0;
    long long power = 1;

    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < nums[i]; j++) {
            power = (power * 100000) % 998244353;
            hash = (hash + (long long)i * power) % 998244353;
        }
    }
    cout<<hash;
    return 0;
}