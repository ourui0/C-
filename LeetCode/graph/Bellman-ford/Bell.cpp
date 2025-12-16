//
// Created by 34021 on 2025/12/13.
//
#include<bits/stdc++.h>
using namespace std;
struct edge {
    int to;
    int w;
    edge(int a,int b):to(a),w(b){}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // vector<list<edge>> adj(n + 1);
    vector<vector<int>> adj;

    for (int i = 0;i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        // adj[u].push_back({v,w});
        adj.push_back({u,v,w});
    }
    int s ,t ,k;
    cin >> s >> t >> k;
    vector<int> min_dist(n + 1,INT_MAX);
    vector<int> dist_copy(n + 1);
    // vector<int> in_queue(n + 1,false);
    // vector<int> cnt(n + 1,0);
    // cnt[1]++;
    // in_queue[1] = true;
    min_dist[s] = 0;
    // queue<int> q;
    // q.push(start);
    // while (!q.empty()) {
    //     for (auto &edge : adj[q.front()]) {
    //         if (min_dist[edge.to] > min_dist[q.front()] + edge.w) {
    //             min_dist[edge.to] = min_dist[q.front()] + edge.w;
    //             if (!in_queue[edge.to]) {
    //                 q.push(edge.to);
    //                 in_queue[edge.to] = true;
    //                 cnt[edge.to]++;
    //                 if (cnt[edge.to] == n) {
    //                     cout << "circle";
    //                     return 0;
    //                 }
    //             }
    //         }
    //     }
    //     in_queue[q.front()] = false;
    //     q.pop();
    // }
    for (int i = 0;i < k + 1;i++) {
        dist_copy = min_dist;
        for (auto &edge : adj) {
            int from = edge[0]; // 边的出发点
            int to = edge[1]; // 边的到达点
            int price = edge[2]; // 边的权值
            // 松弛操作
            if (dist_copy[from] != INT_MAX && min_dist[to] > dist_copy[from] + price) {
                min_dist[to] = dist_copy[from] + price;
            }
        }
    }
    if (min_dist[t]!=INT_MAX) {
        cout << min_dist[t];
    }
    else {
        cout << "unconnected";
    }
    return 0;
}