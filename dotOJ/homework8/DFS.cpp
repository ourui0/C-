//
// Created by 34021 on 2025/11/20.
//
#include<bits/stdc++.h>
using namespace std;
int DFS(int n, vector<vector<int>> graph) {
    int cnt = 0;
    int index = 1;

    vector<bool> visited(n, false);
    stack<int> path;

    visited[0] = true;
    path.push(0);

    while (index < n) {
        if (path.empty()) {
            cnt++;
            path.push(0);
            visited[index] = true;
            path.push(index);
            index++;
            continue;
        }

        int curr = path.top();
        bool found = false;
        for (int v : graph[curr]) {
            if (visited[v]) continue;

            if (v == index) {
                visited[v] = true;
                path.push(v);
                index++;
                found = true;
                break;
            } else {
                cnt++;
                visited[index] = true;
                path.push(index);
                index++;
                found = true;
                break;
            }
        }

        if (!found) {
            path.pop();
        }
    }

    return cnt;
}
void solve() {
    int n,m;
    cin >> n >>m;
    vector<vector<int>> graph(n);

    for (int i = 0;i < m;i++) {
        int u,v;
        cin >> u >> v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n;i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    int ans = DFS(n,graph);
    cout << ans << '\n';
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