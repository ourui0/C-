//
// Created by 34021 on 2025/12/7.
//
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
void bfs(int n,int m,vector<vector<int>> &graph,vector<vector<bool>> &visited) {
    queue<pair<int,int>> q;
    q.push({n,m});
    while(!q.empty()) {
        int x,y;
        x=q.front().first;
        y=q.front().second;
        q.pop();
        visited[x][y]=true;
        for(auto & i : dir) {
            int nn = x + i[0];
            int mn = y + i[1];
            if (nn >= graph.size()||mn>=graph[0].size()||nn < 0||mn < 0) continue;
            if (visited[nn][mn] == false&&graph[nn][mn] == 1) {
                q.push({nn,mn});
            }
        }
    }
}
int solve(int n,int m,vector<vector<int>> &graph,vector<vector<bool>> &visited) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(graph[i][j] == 1&& !visited[i][j]) {
                cnt++;
                bfs(i,j,graph,visited);
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>graph[i][j];
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int ans = solve(n,m,graph,visited);
    cout<<ans<<'\n';
    return 0;
}