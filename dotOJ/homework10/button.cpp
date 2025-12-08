//
// Created by 34021 on 2025/12/7.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


static const ll INF = (1LL<<60);

void solve(int a0, int a1, int a2, int a3) {
    int m;
    cin >> m;

    vector<int> masks;
    vector<int> cost;

    for (int i = 0; i < 4; ++i) {
        masks.push_back(1 << i);
        cost.push_back(a0);
    }
    masks.push_back((1<<0)|(1<<1));
    cost.push_back(a1);
    masks.push_back((1<<2)|(1<<3));
    cost.push_back(a1);
    masks.push_back((1<<0)|(1<<2));
    cost.push_back(a2);
    masks.push_back((1<<1)|(1<<3));
    cost.push_back(a2);
    masks.push_back(0b1111);
    cost.push_back(a3);

    const int N = 16;

    vector<vector<pair<int,int>>> adj(N);
    for (int u = 0; u < N; ++u) {
        for (int i = 0; i < (int)masks.size(); ++i) {
            int v = u ^ masks[i];
            adj[u].push_back({v, cost[i]});
        }
    }

    vector<vector<ll>> dist(N, vector<ll>(N, INF));

    for (int s = 0; s < N; ++s) {
        vector<ll> d(N, INF);
        d[s] = 0;
        using P = pair<ll,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [du, u] = pq.top(); pq.pop();
            if (du != d[u]) continue;
            for (auto &e : adj[u]) {
                int v = e.first, w = e.second;
                if (d[v] > du + w) {
                    d[v] = du + w;
                    pq.push({d[v], v});
                }
            }
        }
        dist[s] = d;
    }

    vector<int> targets;
    targets.reserve(m);

    for (int i = 0; i < m; ++i) {
        string r1, r2;
        cin >> r1 >> r2;

        int s = 0;
        s |= (r1[0]-'0') << 0;
        s |= (r1[1]-'0') << 1;
        s |= (r2[0]-'0') << 2;
        s |= (r2[1]-'0') << 3;

        int needPrefix = s ^ 15;
        targets.push_back(needPrefix);
    }

    sort(targets.begin(), targets.end());
    targets.erase(unique(targets.begin(), targets.end()), targets.end());
    int K = targets.size();

    if (K == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<int> coverAt(N, 0);
    for (int i = 0; i < K; ++i) {
        coverAt[targets[i]] |= (1<<i);
    }

    int FULL = (1<<K) - 1;
    vector<vector<ll>> dp(1<<K, vector<ll>(N, INF));

    int initMask = coverAt[0];
    dp[initMask][0] = 0;

    for (int mask = 0; mask <= FULL; ++mask) {
        for (int u = 0; u < N; ++u) {
            ll cur = dp[mask][u];
            if (cur == INF) continue;

            for (int v = 0; v < N; ++v) {
                if (dist[u][v] == INF) continue;
                int nmask = mask | coverAt[v];
                ll nd = cur + dist[u][v];
                dp[nmask][v] = min(dp[nmask][v], nd);
            }
        }
    }

    ll ans = INF;
    for (int v = 0; v < N; ++v) ans = min(ans, dp[FULL][v]);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, a0, a1, a2, a3;
    cin >> T >> a0 >> a1 >> a2 >> a3;

    while (T--) {
        solve(a0, a1, a2, a3);
    }

    return 0;
}