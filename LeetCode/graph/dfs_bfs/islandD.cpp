//
// Created by 34021 on 2025/12/8.
//
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y,vector<vector<int>> &graph) {
    if (graph[x][y] == 0)return;
    graph[x][y] = 0;

    for (int i = 0;i < 4;i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];

        if (xx < 0||yy < 0||xx >= graph.size()||yy >= graph[0].size())continue;

        dfs(xx,yy,graph);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph(n,vector<int>(m));
    vector<vector<int>> graph2(n,vector<int>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> graph[i][j];
            graph2[i][j] = graph[i][j];
        }
    }

    for (int i = 0;i < m;i++) {
        if (graph[0][i] == 1) {
            dfs(0,i,graph);
        }
        if (graph[n - 1][i] == 1) {
            dfs(n-1,i,graph);
        }
    }

    for (int j = 1;j < n - 1;j++) {
        if (graph[j][0] == 1) {
            dfs(j,0,graph);
        }
        if (graph[j][m - 1] == 1) {
            dfs(j,m - 1,graph);
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (graph[i][j] == 1) {
                cout << 0 << ' ';
            }
            else {
                cout << graph2[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}