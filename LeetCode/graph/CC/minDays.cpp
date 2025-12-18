//
// Created by 34021 on 2025/12/18.
//
#include<bits/stdc++.h>
using namespace std;
struct PairHash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // 更好的哈希组合方式
    }
};
int Time = 1;
unordered_map<pair<int,int>,int, PairHash> dfn;
unordered_map<pair<int,int>,int, PairHash> low;
int cnt = 0;
vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
void Tarjan(pair<int,int> u,pair<int,int> parent,vector<vector<int>>& grid){
    low[u] = dfn[u] = ++Time;
    int child = 0;
    bool is_cut = false;
    for(int i = 0;i < 4;i++){
        int x = u.first + dir[i].first;
        int y = u.second + dir[i].second;
        if(x < 0||y < 0|| x >= grid.size()||y >= grid[0].size())continue;
        if(grid[x][y] != 1)continue;
        pair<int,int> v = {x,y};
        if(v == parent)continue;
        if(dfn[v] == 0){
            Tarjan(v,u,grid);
            child++;
            if (low[v] >= dfn[u]) {
                is_cut = true;
            }
            low[u] = min(low[v],low[u]);
        }
        else{
            low[u] = min(low[v],dfn[u]);
        }
    }
    if(child >= 2)is_cut = true;
    if(is_cut)cnt++;
}
int minDays(vector<vector<int>>& grid) {
    int len_x = grid.size();
    int len_y = grid[0].size();

    for(int i = 0;i < len_x;i++){
        for(int j = 0;j < len_y;j++){
            if(dfn[{i,j}] == 0&&grid[i][j] == 1){
                Tarjan({i,j},{-1,-1},grid);
            }
        }
    }
    return cnt;
}