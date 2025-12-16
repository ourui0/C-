//
// Created by 34021 on 2025/12/12.
//
#include<bits/stdc++.h>
using namespace std;
struct edge {
    int to;
    int w;
    edge(int t,int W):to(t),w(W){}
};
class compare {
public:
    bool operator()(const edge & a,const edge & b) {
        return a.w > b.w;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s,t;
    cin >> n >> m >> s >> t;

    // vector<vector<int>> grid(n+1,vector<int>(n + 1,INT_MAX));
    vector<list<edge>> adj(n + 1);//邻接表
    for (int i = 0;i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        // grid[u][v] = w;
        // grid[v][u] = w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool> visited(n+1,false);
    vector<int> min_dist(n + 1,INT_MAX);
    min_dist[s] = 0;
    visited[s] = true;

    priority_queue<edge,vector<edge>,compare> pq;

    pq.push(edge(s,0));
    while (!pq.empty()) {
        int cur = pq.top().to;
        int min = pq.top().w;
        pq.pop();

        visited[cur] = true;

        for (auto I : adj[cur]) {
            if (!visited[I.to]&&min_dist[I.to] > min_dist[cur] + I.w) {
                min_dist[I.to] = min_dist[cur] + I.w;
                pq.push(edge(I.to,min_dist[I.to]));
            }
        }
    }
    // for (int i = 0;i < n;i++) {
    //     int cur = s;
    //     int min = INT_MAX;
    //
    //     for (int j = 0;j < n;j++) {
    //         if (!visited[j]&&min_dist[j] < min) {
    //             cur = j;
    //             min = min_dist[cur];
    //         }
    //     }
    //
    //     visited[cur] = true;
    //
    //     for (int j = 0;j < n;j++) {
    //         if (!visited[j]&&grid[cur][j] != INT_MAX&&min_dist[j] > min_dist[cur] + grid[cur][j]) {
    //             min_dist[j] = min_dist[cur] + grid[cur][j];
    //         }
    //     }
    // }
    cout << min_dist[t];

}