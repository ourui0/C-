//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;
int Time = 0;
vector<bool> is_ap;
int ap_cnt = 0;
vector<int> low,dfn;
vector<list<int>> adj;
void Tarjan(int u,int parent) {
    int child_cnt = 0;
    low[u] = dfn[u] = ++Time;
    bool is_cut = false;
    for (auto v : adj[u]) {
        if (v == parent)continue;

        if (dfn[v] == 0) {
            child_cnt++;
            Tarjan(v,u);

            if (low[v] >= dfn[u]&&parent != -1) {
                is_cut = true;
            }
            low[u] = min(low[u],low[v]);
        }
        else {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (child_cnt >=2 && parent == -1) {
        is_cut = true;
    }
    if (is_cut) {
        ap_cnt++;
        is_ap[u] = true;
    }
}
void solve(int n) {
    for (int i = 1;i <= n;i++) {
        if (dfn[i] == 0) {
            Tarjan(i,-1);
        }
    }
    cout << ap_cnt <<'\n';
    for (int i = 1;i <= n;i++) {
        if (is_ap[i]) {
            cout << i <<' ';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    is_ap.assign(n + 1,false);
    low.assign(n + 1,0);
    dfn.assign(n + 1,0);
    adj.resize(n + 1);
    for (int i = 0;i < m;i++) {
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    solve(n);
}