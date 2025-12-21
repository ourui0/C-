//
// Created by 34021 on 2025/12/15.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> subtree_size(n, 0);
    vector<long long> dist_sum(n, 0);
    vector<long long> total_dist(n, 0);

    // 第一次DFS：计算子树大小和到子树节点的距离和
    function<void(int, int)> dfs1 = [&](int u, int parent) {
        subtree_size[u] = 1;
        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs1(v, u);
            subtree_size[u] += subtree_size[v];
            dist_sum[u] += dist_sum[v] + subtree_size[v];
        }
    };

    // 第二次DFS：换根DP，计算每个节点到所有节点的距离和
    function<void(int, int)> dfs2 = [&](int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            // 换根公式
            total_dist[v] = total_dist[u] - subtree_size[v] + (n - subtree_size[v]);
            dfs2(v, u);
        }
    };

    dfs1(0, -1);
    total_dist[0] = dist_sum[0];  // 根节点的距离和
    dfs2(0, -1);

    for (int i = 0; i < n; i++) {
        cout << total_dist[i] << (i == n - 1 ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}