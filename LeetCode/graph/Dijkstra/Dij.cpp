//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin >> n >> m >> s;

    vector<list<pair<int,int>>> adj(n + 1);

    for (int i = 0;i < m;i++) {
        int x,y,w;
        cin >> x >> y >> w;

        adj[x].push_back({w,y});
    }

    vector<bool> visited(n + 1,false);

    vector<int> min_dist(n + 1,INT_MAX);

    min_dist[s] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    pq.push({0,s});

    while (!pq.empty()) {
        pair<int,int> cur = pq.top();
        pq.pop();

        if (visited[cur.second])continue;
        visited[cur.second] = true;

        for (auto edge : adj[cur.second]) {
            if (!visited[edge.second] && min_dist[edge.second] > min_dist[cur.second] + edge.first) {
                min_dist[edge.second] = min_dist[cur.second] + edge.first;
                pq.push({min_dist[edge.second],edge.second});
            }
        }
    }

    for (int i = 1;i <=n;i++) {
        cout << min_dist[i] << ' ';
    }

}