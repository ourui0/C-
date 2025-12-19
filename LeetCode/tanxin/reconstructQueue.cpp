//
// Created by 34021 on 2025/12/19.
//
#include<bits/stdc++.h>
using namespace std;
static bool cmp(vector<int> &a,vector<int> &b) {
    return a[0] < b[0];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),cmp);

    list<vector<int>> ans;
    for (auto I : people) {
        int position = I[1];

        std::list<vector<int>>::iterator it = ans.begin();
        while (position--) { // 寻找在插入位置
            it++;
        }
        ans.insert(it, I);
    }
    return vector<vector<int>>(ans.begin(),ans.end());
}
int main() {
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    reconstructQueue(people);
    return 0;
}