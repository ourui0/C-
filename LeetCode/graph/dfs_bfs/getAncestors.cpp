//
// Created by 34021 on 2025/12/17.
//
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> answer(n);
    vector<list<int>> adjT(n);

    for(int i = 0;i < edges.size();i++){
        adjT[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 0;i < n;i++){
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto edge : adjT[cur]){
                if(!visited[edge]){
                    q.push(edge);
                    answer[i].push_back(edge);
                    visited[edge] = true;
                }
            }
        }
        sort(answer[i].begin(),answer[i].end());
    }
    return answer;
}
int main() {

}