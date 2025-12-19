//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;
int scc_cnt = 0;
int Time = 0;
vector<int> low,dfn;
vector<vector<int>> Scc;
vector<list<int>> adj;
vector<int> in_stack;
stack<int> st;
void Tarjan(int u) {
    dfn[u] = low[u] = ++Time;
    st.push(u);
    in_stack[u] = 1;
    for (auto v : adj[u]) {
        if (dfn[v] == 0) {
            Tarjan(v);
            low[u] = min(low[v],low[u]);
        }
        else if (in_stack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        // scc_cnt++;
        vector<int> scc;
        int w;
        int cnt = 0;
        do{
            w = st.top();
            st.pop();
            in_stack[w] = 0;
            cnt++;
            // scc.push_back(w);
        }while(w != u);
        if (cnt >=2)scc_cnt++;
        // sort(scc.begin(),scc.end());
        // Scc.push_back(scc);
    }
}
void solve(int n) {
    for (int i =1;i <= n;i++) {
        if (dfn[i] == 0) {
            Tarjan(i);
        }
    }
    cout << scc_cnt <<'\n';
    // sort(Scc.begin(),Scc.end());
    // for (int i = 0;i <scc_cnt;i++) {
    //     for (auto j : Scc[i]) {
    //         cout << j <<' ';
    //     }
    //     cout <<'\n';
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    adj.resize(n + 1);
    low.assign(n + 1,0);
    dfn.assign(n + 1,0);
    in_stack.assign(n + 1,0);
    for (int i = 0;i < m;i++) {
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    solve(n);
}