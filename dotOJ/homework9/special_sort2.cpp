//
// Created by 34021 on 2025/11/21.
//
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> index(n + 1, 0);//计算入度
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        index[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (index[i] == 0) {
            pq.push(i);
        }
    }
    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            index[v]--;
            if (index[v] == 0) {
                pq.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
