//
// Created by 34021 on 2025/12/17.
//
#include<bits/stdc++.h>
using namespace std;

struct E {
    int to;
    int s;
    int e;
    E(int a,int b,int c):to(a),s(b),e(c){};
};
int minTime(int n, vector<vector<int>>& edges) {
    int start = 0;
    int end = n - 1;
    vector<list<E>> adj(n);

    for (auto edge : edges) {
        adj[edge[0]].push_back(E(edge[1],edge[2],edge[3]));
    }
    vector<int> min_time(n,INT_MAX);
    vector<bool> visited(n,false);
    min_time[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,0});
    while (!q.empty()) {
        auto [cur,m] = q.top();
        q.pop();
        if (visited[cur])continue;
        visited[cur] = true;
        for (auto edge : adj[cur]) {
            int m = max(min_time[cur],edge.s);
            if (!visited[edge.to]&&min_time[edge.to] > m + 1&&min_time[cur]<= edge.e) {
                min_time[edge.to] = m + 1;
                q.push({edge.to,min_time[edge.to]});
            }
        }
    }
    if (min_time[end] == INT_MAX)return -1;
    return min_time[end];
}
int main() {
    vector<vector<int>> edges ={{0,4,20,23},{1,2,25,25},{2,3,4,19},{2,4,4,24},{0,2,5,23}};
    cout << minTime(5,edges);
}