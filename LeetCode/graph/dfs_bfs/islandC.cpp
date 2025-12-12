//
// Created by 34021 on 2025/12/10.
//

#include<bits/stdc++.h>
using namespace std;
vector<pair<int ,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> & graph) {
    int cnt = 0;
    visited[x][y] = true;
    for (int i = 0;i < 4;i++) {
        int xx = x + dir[i].first;
        int yy = y + dir[i].second;

        if (xx < 0||yy < 0|| xx >= graph.size()||yy >= graph[0].size()) {
            cnt++;
            continue;
        }
        if (graph[xx][yy] == 0)cnt++;
        if (graph[xx][yy] == 1&&!visited[xx][yy])cnt += dfs(xx,yy,visited,graph);
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>>  graph(n,vector<int>(m));
    int x = -1,y = -1;
    for (int i = 0;i < n;i++) {
        for (int j = 0; j < m;j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                x = i,y = j;
            }
        }
    }
    if (x != -1) {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int C = dfs(x,y,visited,graph);
        cout << C;
    }
    return 0;
}