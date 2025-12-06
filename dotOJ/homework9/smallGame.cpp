//
// Created by 34021 on 2025/12/2.
//
#include<bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // 检查每个格子值是否合法
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int row = i + 1;
            int col = n + j + 1;
            if (A[i][j] != row && A[i][j] != col) {
                return false;
            }
        }
    }

    // 构建图，节点编号从1到n+m
    int total = n + m;
    vector<vector<int>> graph(total + 1);
    vector<int> indegree(total + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int row = i + 1;
            int col = n + j + 1;
            if (A[i][j] == row) {
                graph[col].push_back(row);
                indegree[row]++;
            } else {
                graph[row].push_back(col);
                indegree[col]++;
            }
        }
    }

    // Kahn算法检测环
    queue<int> q;
    int count = 0;
    for (int i = 1; i <= total; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return count == total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    int ans = 0;
    for (int i = 1; i <= T; i++) {
        if (solve()) {
            ans += i;
        }
    }
    cout << ans << '\n';
    return 0;
}