//
// Created by 34021 on 2025/12/9.
//
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> res;
vector<pair<int,int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};
int cnt = 0;
void dfs(int x,int y,vector<vector<int>> &graph,vector<vector<bool>> &visited, vector<vector<pair<bool,bool>>> &index) {
    if (cnt == 0)index[x][y].first = true;
    if (cnt == 1) index[x][y].second = true;
    visited[x][y] = true;
    for (int i = 0; i < 4;i++) {
        int xx = x + dir[i].first;
        int yy = y + dir[i].second;

        if (xx < 0|| yy < 0|| xx >= graph.size() || yy >= graph[0].size())continue;

        if (graph[xx][yy] >= graph[x][y]&&!visited[xx][yy])dfs(xx,yy,graph,visited,index);
    }
}
void solve(int n,int m,vector<vector<int>> &graph) {
    vector<vector<pair<bool,bool>>> index(n,vector<pair<bool,bool>>(m,{false,false}) );
    for (int i = 0;i < m;i++) {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(0,i,graph,visited,index);
    }
    for (int j = 1;j < n;j++) {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(j,0,graph,visited,index);
    }
    cnt++;
    for (int i = 0;i < m;i++) {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(n-1,i,graph,visited,index);
    }
    for (int j = 0;j < n - 1;j++) {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(j,m - 1,graph,visited,index);
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (index[i][j].first&&index[i][j].second)res.push_back({i,j});
        }
    }
    for (auto i : res) {
        cout << i.first << ' ' <<i.second<<'\n';
    }
}
int  main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph(n,vector<int>(m));
    for (int i = 0;i < n;i++) {
        for (int j= 0; j < m;j++) {
            cin >> graph[i][j];
        }
    }

    solve(n,m,graph);
}