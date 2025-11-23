//
// Created by 34021 on 2025/11/21.
//
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> topolpgicalSort() {
    vector<int> result;
}
void solve() {
    int n,m;
    cin >> n >> m;

    adj.resize(n);

    for (int i = 0;i < m;i++) {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
    }

    vector<int> res = topolpgicalSort();


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
