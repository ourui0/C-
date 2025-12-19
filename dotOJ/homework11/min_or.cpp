//
// Created by 34021 on 2025/12/11.
//
#include <bits/stdc++.h>
using namespace std;

bool check(int n, long long sum, long long mask) {
    long long rem = 0;
    for (int i = 60; i >= 0; --i) {
        long long bit_val = (sum >> i) & 1;
        rem = rem * 2 + bit_val;

        if ((mask >> i) & 1) {
            rem -= min(rem, (long long)n);
        }
    }
    return rem == 0;
}

void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        sum += x;
    }

    long long ans = 0;

    for (int b = 60; b >= 0; --b) {
        long long temp_mask = ans | ((1LL << b) - 1);
        if (check(n, sum, temp_mask)) {
        } else {
            ans |= (1LL << b);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}