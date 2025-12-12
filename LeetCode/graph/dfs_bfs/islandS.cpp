//
// Created by 34021 on 2025/12/8.
//
#include<bits/stdc++.h>
using namespace std;
bool judge = false;
vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> &graph) {
    if (visited[x][y] == true||graph[x][y] == 0)return 0;
    int cnt = 1;
    visited[x][y] = true;
    for (int i = 0;i < 4;i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0|| yy < 0||xx >= visited.size()||yy >= visited[0].size())continue;
        cnt += dfs(xx,yy,visited,graph);
    }
    return cnt;
}
int bfs(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> &graph) {
    int cnt = 1;
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0;i < 4;i++) {
            int xx = cur_x + dir[i][0];
            int yy = cur_y + dir[i][1];
            if (xx < 0|| yy < 0||xx >= visited.size()||yy >= visited[0].size())continue;
            if (graph[xx][yy] == 1 && visited[xx][yy] == false) {
                q.push({xx,yy});
                cnt++;
                visited[xx][yy] = true;
            }
        }
    }
    return cnt;
}
int dfs1(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> &graph) {
    if (visited[x][y] == true||graph[x][y] == 0)return 0;
    if (x == 0|| y == 0||x == visited.size() - 1||y == visited[0].size()-1)judge = true;
    int cnt = 1;
    visited[x][y] = true;
    for (int i = 0;i < 4;i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0|| yy < 0||xx >= visited.size()||yy >= visited[0].size())continue;
        cnt += dfs1(xx,yy,visited,graph);
    }
    if (judge)return 0;
    return cnt;
}
int bfs1(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> &graph) {
    int cnt = 1;
    judge = false;
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0;i < 4;i++) {
            int xx = cur_x + dir[i][0];
            int yy = cur_y + dir[i][1];
            if (xx < 0|| yy < 0||xx >= visited.size()||yy >= visited[0].size())continue;
            if (graph[xx][yy] == 1 && visited[xx][yy] == false) {
                if (xx == 0||yy==0||xx == visited.size() - 1||yy == visited[0].size() - 1) {
                    judge = true;
                }
                q.push({xx,yy});
                cnt++;
                visited[xx][yy] = true;
            }
        }
    }
    if (judge) {
        return 0;
    }
    return cnt;
}
void solve(int N,int M,vector<vector<int>> &graph) {
    int Max = 0;
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    for (int i = 1;i < N - 1;i++) {
        for (int j = 1;j < M - 1;j++) {
            if (graph[i][j] == 1&&!visited[i][j]) {
                // cnt += dfs(i,j,visited,graph);
                judge = false;
                Max += dfs1(i,j,visited,graph);
            }
        }
    }
    cout << Max;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<vector<int>> graph(N,vector<int>(M));

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> graph[i][j];
        }
    }

    solve(N,M,graph);

    return 0;
}