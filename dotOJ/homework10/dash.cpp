//
// Created by 34021 on 2025/12/6.
//
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
using ld = long double;
ld solve(int n,int sx,int sy,int tx,int ty,int v1,int v2,vector<pair<int,int>> &point) {
    vector<pair<ld,ld>> adj(n + 2);
    adj[0] = {sx,sy};//起点

    for (int i = 1; i <= n; i++) {
        adj[i] = {point[i].first,point[i].second};
    }
    adj[n + 1] = {tx,ty};//终点

    vector<vector<ld> > dist(n + 2,vector<ld>(n + 2,0));

    for (int i = 0; i <= n + 1; i++) {
        for (int j = i + 1; j <= n + 1; j++) {
            ld d = (ld)(adj[i].first - adj[j].first);
            ld h = (ld)(adj[i].second - adj[j].second);
            dist[i][j] = dist[j][i] = sqrtl(d * d + h * h);
        }
    }

    vector<ld> d(n + 2, 1e18);
    d[0] = 0;

    vector<bool> v(n + 2, false);

    for (int i = 0; i < n + 2; ++i) {
        int u = -1;
        ld min_dis = 1e18;
        for (int j = 0; j < n + 2; ++j) {
            if (!v[j] && d[j] < min_dis) {
                min_dis = d[j];
                u = j;
            }
        }
        if (u == -1) break;   // 所有点已访问
        v[u] = true;
        if (u == n + 1) break; // 终点已确定最短时间

        for (int j = 0; j < n + 2; j++) {
            if (v[j]) continue;
            ld c ;
            if (u == 0) {  // 从起点出发，无加速
                c  = dist[u][j] / v1;
            } else if (u >= 1 && u <= n) {  // 从冲刺点出发，有加速
                ld D = dist[u][j];
                if (D <= 3.0 * v2) {
                    c  = D / v2;
                } else {
                    c  = 3.0 + (D - 3.0 * v2) / v1;
                }
            } else {  // 从终点出发，不处理
                continue;
            }
            if (d[u] + c  < d[j]) {
                d[j] = d[u] + c ;
            }
        }
    }

    return d[n + 1];
}
int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,sx,sy,tx,ty,v1,v2;
    cin >> n;

    vector<pair<int,int>> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i].first >> v[i].second;
    }
    cin >> sx >> sy >> tx >> ty >> v1 >> v2;

    ld ans = solve(n,sx,sy,tx,ty,v1,v2,v);
    cout << fixed << setprecision(12) << ans << endl;
}