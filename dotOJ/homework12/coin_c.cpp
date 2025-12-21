//
// Created by 34021 on 2025/12/15.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum;
    cin >> sum;

    vector<int> coins;
    int c;
    while (cin >> c) {
        coins.push_back(c);
    }
    sort(coins.begin(),coins.end());
    vector<int> dp(sum + 1,0);
    for (auto coin : coins) {
        for (int i = 1;i <= sum;i++) {
            if (coin == i) {
                dp[i]++;
            }
            if (coin < i) {
                dp[i] += dp[i - coin];
            }
        }
    }
    cout << dp[sum];
    return 0;
}