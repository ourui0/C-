//
// Created by 34021 on 2025/12/17.
//
#include<bits/stdc++.h>
using namespace std;

bool canReach(vector<int>& arr, int start) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(arr.size(),false);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (arr[cur] == 0)return true;

        if (cur + arr[cur] < arr.size()&&!visited[cur + arr[cur]]) {
            q.push(cur + arr[cur]);
            visited[cur + arr[cur]] = true;
        }
        if (cur - arr[cur] >= 0 &&!visited[cur - arr[cur]]) {
            q.push(cur - arr[cur]);
            visited[cur - arr[cur]] = true;
        }
    }
    return false;
}
int main() {
    vector<int> nums = {4,2,3,0,3,1,2};
    cout << canReach(nums,5);
    return 0;
}