//
// Created by 34021 on 2025/12/17.
//
#include<bits/stdc++.h>
using namespace std;
static unordered_map<string,int> str_map;
static bool cmp(string a,string b) {
    if (str_map[a]!=str_map[b]) {
        return str_map[a] < str_map[b];
    }
    else {
        return a < b;
    }
}
vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    vector<string> ans;

    vector<int> visited(friends.size(),false);
    queue<int> q;
    q.push(id);
    visited[id] = true;
    while (level--) {
        int size = q.size();
        while (size--) {
            int t = q.front();
            q.pop();
            for (int i : friends[t]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (const auto& video : watchedVideos[cur]) {
            str_map[video]++;
            if (str_map[video] == 1) {
                ans.push_back(video);
            }
        }
    }

    sort(ans.begin(),ans.end(),cmp);
    return ans;
}
int main() {
    vector<vector<string>> Videos = {{"A","B"},{"C"},{"B","C"},{"D"},{"e"},{"f"},{"G"}};
    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2},{6},{5},{1,2,3}};
    watchedVideosByFriends(Videos,friends,0,1);
}