//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;

    vector<list<pair<int,int>>> adj(n + 1);

    for (int i = 0;i < m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        if (z < 0) {
            adj[x].push_back({y,z});
        }
        else {
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
    }

    vector<int> cnt(n + 1,0);
    vector<bool> in_queue(n + 1,false);
    vector<int> dist(n + 1,INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] != INT_MAX &&dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                // 记录路径边数，这比记录入队次数更稳定
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    cout << "YES" << endl;
                    return;
                }
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
    cout << "NO"<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}