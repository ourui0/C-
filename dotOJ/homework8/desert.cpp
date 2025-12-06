//
// Created by 34021 on 2025/11/20.
//

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 300005;

class Graph {
private:
    vector<vector<pair<int, int>>> graph;
    vector<int> discovery, low, parent;
    vector<int> cycle_sizes;
    ll bridge_count;
    int timer;

    vector<ll> nums;

    void Num(int max_power) {
        nums.resize(max_power + 1);
        nums[0] = 1;
        for (int i = 1; i <= max_power; i++) {
            nums[i] = (nums[i-1] * 2) % MOD;
        }
    }

    ll get_power(int k) {
        if (k < nums.size()) return nums[k];
        // 备用计算，正常情况下不会执行
        ll res = 1;
        for (int i = 0; i < k; i++) {
            res = (res * 2) % MOD;
        }
        return res;
    }

    void dfs(int u, int p) {
        discovery[u] = low[u] = ++timer;
        parent[u] = p;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            if (v == p) continue;

            if (discovery[v]) {
                low[u] = min(low[u], discovery[v]);
                if (discovery[v] < discovery[u]) {
                    // 发现环
                    int cycle_size = 1;
                    for (int curr = u; curr != v; curr = parent[curr]) {
                        cycle_size++;
                    }
                    cycle_sizes.push_back(cycle_size);
                }
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > discovery[u]) {
                    bridge_count++;
                }
            }
        }
    }

public:
    Graph(int n) : graph(n), discovery(n), low(n), parent(n) {}

    void add_edge(int u, int v, int idx) {
        graph[u].push_back({v, idx});
        graph[v].push_back({u, idx});
    }

    ll compute() {
        int n = graph.size();
        discovery.assign(n, 0);
        low.assign(n, 0);
        parent.assign(n, -1);

        Num(n); // 最大环长不会超过n

        ll cnt = 1;

        for (int i = 0; i < n; i++) {
            if (!discovery[i]) {
                timer = 0;
                bridge_count = 0;
                cycle_sizes.clear();
                dfs(i, -1);

                ll component = get_power(bridge_count);

                for (int size : cycle_sizes) {
                    ll cycle_ways = (get_power(size) - 1 + MOD) % MOD;
                    component = (component * cycle_ways) % MOD;
                }

                cnt = (cnt * component) % MOD;
            }
        }

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u-1, v-1, i);
    }

    ll ans = graph.compute();
    cout << ans << '\n';

    return 0;
}