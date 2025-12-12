//
// Created by 34021 on 2025/12/9.
//
#include<bits/stdc++.h>
using namespace std;
struct point {
    int val;
    int num;
};
int num = 0;
vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y,vector<vector<bool>> &visited,vector<vector<point>> &graph) {
    if (visited[x][y] == true||graph[x][y].val == 0)return 0;
    int cnt = 1;
    visited[x][y] = true;
    graph[x][y].num = num;
    for (int i = 0;i < 4;i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0|| yy < 0||xx >= visited.size()||yy >= visited[0].size())continue;
        cnt += dfs(xx,yy,visited,graph);
    }
    return cnt;
}
void solve(int n,int m,vector<vector<point>> &graph) {
    vector<int> S;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (graph[i][j].val == 1&&!visited[i][j]) {
                S.push_back(dfs(i,j,visited,graph));
                num++;
            }
        }
    }
    int Max = S[0];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (graph[i][j].val == 0) {
                int temp = 1;
                vector<bool> t(S.size(),false);
                for (int k = 0;k < 4;k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0|| y < 0||x >= n||y >= m)continue;
                    if (graph[x][y].val == 1&&!t[graph[x][y].num]) {
                        temp += S[graph[x][y].num];
                        t[graph[x][y].num] = true;
                    }
                }
                if (temp > Max)Max = temp;
            }
        }
    }
    cout << Max;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<point>> graph(n,vector<point>(m));
    for (int i = 0;i < n;i++) {
        for (int j= 0; j < m;j++) {
            cin >> graph[i][j].val;
        }
    }

    solve(n,m,graph);

    return 0;
}