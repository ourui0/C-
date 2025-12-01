//
// Created by 34021 on 2025/10/10.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 100005;

vector<pair<ll, ll>> graph[MAXN];
vector<ll> stk;
vector<ll> stkEdge;
vector<ll> inStack, visited;

vector<ll> bestCycle;

bool isBetter(const vector<ll>& cur, const vector<ll>& best) {
    if (best.empty()) return true;
    if (cur.empty()) return false;

    // 由于边权是 2^i，环的周长由最大边编号决定
    // 最大编号小的环周长更小，如果最大编号相同则比较次大编号
    vector<ll> a = cur, b = best;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // 比较字典序，小的更优
    for (size_t i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    // 如果前面都相同，边数少的更优
    return a.size() < b.size();
}

void dfs(ll u, ll parentEdge) {
    visited[u] = 1;
    inStack[u] = 1;
    stk.push_back(u);
    stkEdge.push_back(parentEdge);

    for (auto& nx : graph[u]) {
        ll v = nx.first;
        ll eidx = nx.second;
        if (eidx == parentEdge) continue;

        if (!visited[v]) {
            dfs(v, eidx);
        } else if (inStack[v]) {
            // 找到环
            vector<ll> cycleEdges;
            cycleEdges.push_back(eidx);  // 当前边

            // 从栈中提取环的其他边
            for (ll i = stk.size() - 1; i >= 0; i--) {
                if (stk[i] == v) break;
                if (stkEdge[i] != -1) {  // 排除起始的-1
                    cycleEdges.push_back(stkEdge[i]);
                }
            }

            sort(cycleEdges.begin(), cycleEdges.end());

            if (isBetter(cycleEdges, bestCycle)) {
                bestCycle = cycleEdges;
            }
        }
    }

    inStack[u] = 0;
    stk.pop_back();
    stkEdge.pop_back();
}

void solve() {
    ll n, m;
    cin >> n >> m;

    // 初始化
    stk.clear();
    stkEdge.clear();
    bestCycle.clear();
    for (ll i = 0; i < n; i++) {
        graph[i].clear();
    }

    visited.assign(n, 0);
    inStack.assign(n, 0);

    // 建图
    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    // DFS找环
    for (ll i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    // 输出结果
    if (bestCycle.empty()) {
        cout << -1 << "\n";
    } else {
        // 题目要求输出边的编号（已经是对数值）
        sort(bestCycle.begin(), bestCycle.end());
        for (size_t i = 0; i < bestCycle.size(); i++) {
            cout << bestCycle[i];
            if (i != bestCycle.size() - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}