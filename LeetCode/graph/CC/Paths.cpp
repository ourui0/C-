#include <bits/stdc++.h>
using namespace std;

// 结构体存储边信息，更高效
struct Edge {
    int to;
    int id;
};

int Time;
vector<int> dfn, low;
vector<vector<Edge>> adj;
vector<bool> isBridge; // 使用数组标记桥，O(1)访问

void Tarjan(int u, int parentEdgeId) {
    dfn[u] = low[u] = ++Time;
    for (auto &edge : adj[u]) {
        if (edge.id == parentEdgeId) continue; // 只有完全相同的边才跳过

        if (!dfn[edge.to]) {
            Tarjan(edge.to, edge.id);
            low[u] = min(low[u], low[edge.to]);
            if (low[edge.to] > dfn[u]) {
                isBridge[edge.id] = true; // 标记该 ID 的边为桥
            }
        } else {
            low[u] = min(low[u], dfn[edge.to]);
        }
    }
}

void solve() {
    int n = adj.size() - 1;
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    Time = 0;

    // 1. 找桥
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) Tarjan(i, -1);
    }

    // 2. 搜集边双 (使用简单的 DFS 替代队列 BFS 速度更快)
    vector<vector<int>> bccs;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> current_bcc;
            stack<int> s;
            s.push(i);
            visited[i] = true;

            while (!s.empty()) {
                int u = s.top();
                s.pop();
                current_bcc.push_back(u);
                for (auto &edge : adj[u]) {
                    if (isBridge[edge.id]) continue; // 桥不能过
                    if (!visited[edge.to]) {
                        visited[edge.to] = true;
                        s.push(edge.to);
                    }
                }
            }
            bccs.push_back(current_bcc);
        }
    }

    // 输出
    cout << bccs.size() << '\n';
    for (auto &bcc : bccs) {
        cout << bcc.size() << " ";
        for (int node : bcc) cout << node << " ";
        cout << '\n';
    }
}

int main() {
    // 极致 IO 优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F, R;
    if (!(cin >> F >> R)) return 0;

    adj.assign(F + 1, vector<Edge>());
    isBridge.assign(R + 1, false);

    for (int i = 1; i <= R; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue; // 自环处理：不影响边双，但没必要建边

        // 给每条边分配唯一的 i，即使是重边，ID 也不一样
        // 这样在 Tarjan 中，只有原路返回的边会被跳过，重边会正常更新 low 值
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    solve();
    return 0;
}