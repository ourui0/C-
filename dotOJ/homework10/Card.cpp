//
// Created by 34021 on 2025/12/6.
//
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge {
    int u;
    int v;
    int val;
};
ll solve(int n,int m,vector<Edge> &edges) {
    const ll INF = 1e18;

    //构建反图
    vector<vector<Edge>> adj(n + 1);
    vector<Edge> Edges;

    for (int i = 1;i <= m;i++) {
        int v = edges[i].v;
        adj[v].push_back({edges[i].v,edges[i].u,edges[i].val});
        Edges.push_back({edges[i].v,edges[i].u,edges[i].val});
    }

    for (int i = 1; i <= n; i++) {
        adj[0].push_back({0,i,0});
        Edges.push_back({0,i,0});
    }

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    vector<bool> pos(n + 1, false);

    for (int i = 1; i <= n; i++) {
        bool index = false;
        for (int j = 0;j < m + n;j++) {
            int u = Edges[j].u;
            int v = Edges[j].v;
            int w = Edges[j].val;
            if (dp[u] != INF && dp[u] + w < dp[v]) {
                dp[v] = dp[u] + w;
                index = true;
            }
        }
        if (!index) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0;j < m + n;j++) {
            int u = Edges[j].u;
            int v = Edges[j].v;
            int w = Edges[j].val;
            if (pos[u] || (dp[u] != INF && dp[u] + w < dp[v])) {
                pos[v] = true;
            }
        }
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i]) {
            cnt++;
        }
    }

    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<Edge> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].val;
    }

    ll ans = solve(n,m,edges);

    cout << ans;
}