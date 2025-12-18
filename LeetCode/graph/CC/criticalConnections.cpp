//
// Created by 34021 on 2025/12/18.
//
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
int Time = 1;
vector<int> dfn;
vector<int> low;
stack<int> st;
vector<list<int>> adj;
void Tarjan(int u,int parent) {
    dfn[u] = low[u] = ++Time;
    for (auto v : adj[u]) {
        if (v == parent)continue;
        if (dfn[v] == 0) {
            Tarjan(v,u);
            if (low[v] > low[u]) {
                ans.push_back({u,v});
            }
            else {
                low[u] = min(low[u],low[v]);
            }
        }
        else {
            low[u] = min(low[u],dfn[v]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    dfn.assign(n,0);
    low.assign(n,0);
    adj.resize(n);
    for (auto edge : connections) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for (int i = 0;i < n;i++) {
        if (dfn[i] == 0) {
            Tarjan(i,-1);
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    criticalConnections(4,connections);
    return 0;
}