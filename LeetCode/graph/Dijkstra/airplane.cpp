//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node {
    int u, used; // 当前城市，已用免费次数
    ll d;
    Node(int x,int y,ll w):u(x),d(w),used(y){};
    bool operator > (const Node& other) const { return d > other.d; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    int s,t;
    cin >> s >> t;
    vector<list<Node>> adj(n);
    for (int i = 0;i < m;i++) {
        int x, y,w;
        cin >> x >> y >> w;

        adj[x].push_back(Node(y,0,w));
        adj[y].push_back(Node(x,0,w));
    }

    vector<vector<ll>> min_dist(n,vector<ll>(k + 1,INT_MAX));

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    min_dist[s][0] = 0;
    pq.push({s, 0, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int u = cur.u;
        int used = cur.used;
        ll d = cur.d;

        // 标准 Dijkstra 优化：如果当前距离已经不是最优，跳过
        if (d > min_dist[u][used]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.u;
            int w = edge.d;

            // 决策 1：不使用优惠，正常付费买票
            if (min_dist[v][used] > d + w) {
                min_dist[v][used] = d + w;
                pq.push({v, used, min_dist[v][used]});
            }

            // 决策 2：使用一次优惠（前提是还有剩余次数）
            if (used < k && min_dist[v][used + 1] > d) {
                min_dist[v][used + 1] = d; // 权值为 0，所以距离不增加
                pq.push({v, used + 1, min_dist[v][used + 1]});
            }
        }
    }
    ll ans = INT_MAX;
    for (int i = 0;i <= k;i++) {
        ans = min(ans,min_dist[t][i]);
    }
    cout << ans;

}