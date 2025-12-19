//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;
int Time = 1;
stack<pair<int,int>> st;
vector<bool> is_ap;
vector<int> dfn;
vector<int> low;
vector<list<int>> adj;
vector<vector<int>> Bcc;
vector<int> bcc_visited;
int bcc_cnt = 0;       // 记录目前找到了第几个 BCC
void Tarjan(int u,int parent) {
    bool is_cut = false;
    int child = 0;
    dfn[u] = low[u] = ++Time;
    if (adj[u].empty()) {
        bcc_cnt++;
        Bcc.push_back({u});
    }
    for (auto v : adj[u]) {
        if (v == parent)continue;

        if (dfn[v] == 0) {
            st.push({u,v});
            Tarjan(v,u);
            child++;
            if (low[v] >= dfn[u]) {
                bcc_cnt++;
                vector<int> cur;
                while (true) {
                    pair<int,int> edge = st.top();
                    st.pop();
                    if (bcc_visited[edge.first] != bcc_cnt) {
                        cur.push_back(edge.first);
                        bcc_visited[edge.first] = bcc_cnt;
                    }
                    if (bcc_visited[edge.second] != bcc_cnt) {
                        cur.push_back(edge.second);
                        bcc_visited[edge.second] = bcc_cnt;
                    }
                    if (edge.first == u && edge.second == v) break;
                }
                Bcc.push_back(cur);
            }
            low[u] = min(low[u],low[v]);
        }
        else if(dfn[v] < dfn[u]){
            st.push({u,v});
            low[u] = min(dfn[v],low[u]);
        }
    }
}
void solve(int n) {
    vector<bool> visited(n + 1,false);
    //遍历寻找断点
    for (int i = 1;i <= n;i++) {
        if (dfn[i] == 0) {
            Tarjan(i,-1);
        }
    }

    cout << bcc_cnt <<'\n';
    for (int i = 0;i < bcc_cnt;i++) {
        cout << Bcc[i].size() <<' ';
        for (auto j : Bcc[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    adj.resize(n + 1);
    is_ap.assign(n + 1,false);
    dfn.assign(n + 1,0);
    low.assign(n + 1,0);
    bcc_visited.assign(n + 1,0);
    for (int i = 0;i < m;i++) {
        int x,y;
        cin >> x >> y;
        if (x == y) {
            bcc_cnt++;
            Bcc.push_back({x});
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    solve(n);
    return 0;
}