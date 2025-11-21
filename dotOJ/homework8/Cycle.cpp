//
// Created by 34021 on 2025/11/20.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int parent[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
    }
}

vector<vector<pair<int, int>>> graph;

bool isBetter(const vector<int> &curCycle, const vector<int> &bestCycle) {
    if (bestCycle.empty()) return true;
    if (curCycle.empty()) return false;

    vector<int> a = curCycle;
    vector<int> b = bestCycle;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    return a < b;
}

vector<int> bfs(int s, int t, int n) {
    vector<int> pre_node(n, -1);
    vector<int> pre_edge(n, -1);
    queue<int> q;
    q.push(s);
    pre_node[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) {
            break;
        }
        for (auto &[v, idx] : graph[u]) {
            if (pre_node[v] == -1) {
                pre_node[v] = u;
                pre_edge[v] = idx;
                q.push(v);
            }
        }
    }
    vector<int> path;
    int cur = t;
    while (cur != s) {
        path.push_back(pre_edge[cur]);
        cur = pre_node[cur];
    }
    return path;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    graph.assign(n, vector<pair<int, int>>());

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
    }

    vector<int> best_cycle;
    bool found = false;

    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (find(u) == find(v)) {
            vector<int> path_edges = bfs(u, v, n);
            path_edges.push_back(i + 1);

            if (!found || isBetter(path_edges, best_cycle)) {
                best_cycle = path_edges;
                found = true;
                break;
            }
        } else {
            unite(u, v);
            graph[u].push_back({v, i + 1});
            graph[v].push_back({u, i + 1});
        }
    }

    if (!found) {
        cout << -1 << '\n';
    } else {
        sort(best_cycle.begin(), best_cycle.end());
        for (size_t j = 0; j < best_cycle.size(); j++) {
            cout << best_cycle[j] << (j == best_cycle.size() - 1 ? "\n" : " ");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}