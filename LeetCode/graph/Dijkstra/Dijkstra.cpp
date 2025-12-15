//
// Created by 34021 on 2025/12/12.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> grid(N + 1,vector<int>(N + 1,INT_MAX));//图的构建

    for(int i=0;i<M;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        grid[x][y]=z;
    }
    int start = 1;
    int end = N;

    vector<int> min_dist(N+1,INT_MAX);
    vector<bool> visited(N+1,false);
    min_dist[start]=0;
    visited[start]=true;

    for (int i = 1; i <= N; i++) {
        int cur = start;
        int min = INT_MAX;
        for (int j = 1; j <= N; j++) {
            if (min_dist[j] <  min&& !visited[j]) {
                cur = j;
                min = min_dist[cur];
            }
        }
        visited[cur]=true;
        for (int j = 1; j <= N; j++) {
            if (!visited[j] && grid[cur][j] != INT_MAX && min_dist[cur] + grid[cur][j] < min_dist[j]) {
                min_dist[j] = min_dist[cur] + grid[cur][j];
            }
        }
    }
    if (min_dist[N] != INT_MAX) {
        cout<<min_dist[N]<<'\n';
    }
    else {
        cout<<"-1"<<'\n';
    }
}