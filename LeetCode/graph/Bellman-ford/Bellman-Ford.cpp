//
// Created by 34021 on 2025/12/13.
//
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n ,m ,W;
    cin >> n >> m >> W;

    vector<vector<int>> adj(n + 1,vector<int>(n + 1,0));
    for (int i = 0;i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    for (int i = 0; i < W;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] -= w;
    }
    queue<int> q;
    vector<int> min_dist(n + 1,INT_MAX);
    vector<int> cnt(n + 1,0);
    cnt[1]++;
    min_dist[1] = 0;
    vector<bool> in_queue(n + 1,false);
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        in_queue[node] = false;
        q.pop();
        for (int i = 1;i <= n;i++) {
            if (adj[node][i] != 0&&min_dist[i] > min_dist[node] + adj[node][i]) {
                min_dist[i] = min_dist[node] + adj[node][i];
                if (!in_queue[i]) {
                    q.push(i);
                    in_queue[i] =true;
                    cnt[i]++;
                    if (cnt[i] == n) {
                        cout << "YES"<<'\n';
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int F;
    cin >> F;
    while (F--) {
        solve();
    }
    return 0;
}