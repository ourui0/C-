//
// Created by 34021 on 2025/12/16.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<int> A(m);
    for (int i = 0;i < m;i++) {
        cin >> A[i];
    }

    vector<vector<vector<int>>> grid(n + 1,vector<vector<int>>(n + 1,vector<int>(n + 1,100005)));

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> grid[i][j][0];
        }
    }
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                grid[i][j][k] = min(grid[i][j][k - 1],grid[i][k][k-1]+ grid[k][j][k-1]);
            }
        }
    }
    long long ans = 0;
    ans += grid[1][A[0]][n];
    for (int i = 0;i < m - 1;i++) {
        ans += grid[A[i]][A[i + 1]][n];
    }
    ans += grid[A[m - 1]][n][n];
    cout << ans;
}