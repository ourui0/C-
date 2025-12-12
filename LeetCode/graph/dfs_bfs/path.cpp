//
// Created by 34021 on 2025/12/7.
//
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void dfs(int n,vector<list<int>> &v,int r) {
    if (r == n) {
        result.push_back(path);
        return;
    }
    for (auto x: v[r]) {
        path.push_back(x);
        dfs(n,v,x);
        path.pop_back();
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<list<int>> v(n + 1);
    for (int i = 1; i <= m; i++) {
        int s,t;
        cin >> s >> t;
        v[s].push_back(t);
    }
    path.push_back(1);
    dfs(n,v,1);
    if (result.empty()) {
        cout << -1;
    }
    else {
        for (auto p : result) {
            int size = p.size();
            for (int i = 0; i < size; i++) {
                cout << p[i] << (i != size - 1 ? " " : "");
            }
            cout << '\n';
        }
    }
    return 0;
}