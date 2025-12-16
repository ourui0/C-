//
// Created by 34021 on 2025/12/11.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = a[0];
        for (int i = 1; i < n; i++) {
            ans &= a[i];
        }
        cout << ans << "\n";
    }

    return 0;
}