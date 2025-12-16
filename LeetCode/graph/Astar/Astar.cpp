//
// Created by 34021 on 2025/12/13.
//
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dir = {
    {2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},
       {-2,1},{-1,2},{1,2}
};
void solve() {
    int sx,sy,ex,ey;
    cin >> sx >>sy >>ex >>ey;
    if (sx == ex&&sy == ey) {
        cout << 0 << '\n';
        return;
    }
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vector<vector<bool>> ChessBoard(1001,vector<bool>(1001));
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<int,int> cur =q.front();
            q.pop();
            for (int i = 0;i < 8;i++) {
                int x = cur.first + dir[i].first;
                int y = cur.second + dir[i].second;
                if (x <= 0 || y <= 0||x > 1000 || y > 1000)continue;
                if (x == ex&&y==ey) {
                    cout << cnt + 1 <<'\n';
                    return;
                }
                if (!ChessBoard[x][y]) {
                    q.push({x,y});
                    ChessBoard[x][y] = true;
                }
            }
        }
        cnt++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}