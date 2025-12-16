//
// Created by 34021 on 2025/12/16.
//
#include<bits/stdc++.h>
using namespace std;
// struct edge {
//     int to;
//     int w;
//     edge(int to, int w):to(to),w(w) {}
// };
// class myCompare {
// public:
//     bool operator() (const edge& a, const edge& b) {
//         return a.w > b.w;
//     }
// };
// void solve(int n,vector<list<edge>> &adj) {
//     int start,end;
//     cin >> start >> end;
//     vector<int> min_dist(n + 1,INT_MAX);
//     vector<bool> visited(n + 1,false);
//
//     priority_queue<edge, vector<edge>, myCompare> pq;
//
//     min_dist[start] = 0;
//     pq.push(edge(start,0));
//
//     while (!pq.empty()) {
//         edge e = pq.top();
//         pq.pop();
//         if (visited[e.to] == true)continue;
//         visited[e.to] = true;
//
//         for (auto x : adj[e.to]) {
//             if (!visited[x.to] && min_dist[x.to] > min_dist[e.to] + x.w) {
//                 min_dist[x.to] = min_dist[e.to] + x.w;
//                 pq.push(edge(x.to,min_dist[x.to]));
//             }
//         }
//     }
//     if (min_dist[end] != INT_MAX) {
//         cout << min_dist[end] << '\n';
//     }
//     else {
//         cout << -1 << '\n';
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // vector<list<edge>> adj(n + 1);
    vector<vector<vector<int>>> grid(n + 1, vector<vector<int>>(n + 1,vector<int>(n + 1,10005)));
    for (int i = 0;i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        // adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
        grid[u][v][0] = w;
        grid[v][u][0] = w;
    }

    for (int k = 1;k <= n;k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j][k] = min(grid[i][j][k-1], grid[i][k][k-1] + grid[k][j][k-1]);
            }
        }
    }
    int q;
    cin >> q;

    while (q--) {
        // solve(n,adj);
        int x,y;
        cin >> x >> y;
        if (grid[x][y][n] == 10005) {
            cout << -1 << '\n';
        }
        else {
            cout << grid[x][y][n] << '\n';
        }
    }
}