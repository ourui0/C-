//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;
vector<int> scc_id;       // 每个点属于哪个 SCC
vector<int> scc_weight;   // 每个 SCC 的总权值
int scc_cnt = 0;
int Time = 0;
vector<int> weights,low,dfn;
vector<bool> in_stack;
stack<int> st;
vector<list<int>> adj;
void Tarjan(int u) {
    low[u] = dfn[u] = ++Time;
    st.push(u);
    in_stack[u] = true;

    for (auto v : adj[u]) {
        if (dfn[v] == 0) {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if (in_stack[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        scc_cnt++;
        int w = 0;
        do {
            w = st.top();
            st.pop();
            scc_id[w] = scc_cnt;
            scc_weight[scc_cnt] += weights[w];
            in_stack[w] = false;
        }while (w != u);
    }
}
void solve(int n) {
    for (int i = 1;i <= n;i++) {
        if (dfn[i] == 0) {
            Tarjan(i);
        }
    }

    // 假设已经得到了 scc_id[], scc_weight[], scc_cnt
    vector<int> f(scc_cnt + 1, 0);
    vector<int> in_deg(scc_cnt + 1, 0);
    vector<vector<int>> dag_adj(scc_cnt + 1);

    // 1. 构建 DAG 并统计入度
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc_id[u] != scc_id[v]) {
                dag_adj[scc_id[u]].push_back(scc_id[v]);
                in_deg[scc_id[v]]++;
            }
        }
    }

    // 2. 拓扑排序进行 DP
    queue<int> q;
    for (int i = 1; i <= scc_cnt; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
            f[i] = scc_weight[i]; // 起点的初始权值
        }
    }

    int final_max = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        final_max = max(final_max, f[u]); // 更新全局最大值

        for (int v : dag_adj[u]) {
            // 状态转移方程
            f[v] = max(f[v], f[u] + scc_weight[v]);

            in_deg[v]--;
            if (in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << final_max << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    dfn.assign(n + 1,0);
    low.assign(n + 1,0);
    in_stack.assign(n + 1,0);
    adj.resize(n + 1);
    weights.resize(n + 1);
    scc_id.assign(n + 1,0);
    scc_weight.assign(n + 1,0);
    for (int i = 1;i <= n;i++) {
        cin >> weights[i];
    }
    for (int i = 0;i < m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    solve(n);
    return 0;
}