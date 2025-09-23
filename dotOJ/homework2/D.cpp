//
// Created by 34021 on 2025/9/19.
//
#include<bits/stdc++.h>
using namespace std;
struct point {
    int x;
    int y;
};
long double round(vector<point> v) {
    for (auto &p : v) {
        p.y = abs(p.y);
    }

    long double maxR = 0;
    for (auto &p : v) {
        long double need = ((long double)p.x * p.x + (long double)p.y * p.y) / (2.0 * p.y);
        maxR = max(maxR, need);
    }

    long double L_Y = 0, R_Y = maxR;

    for (int iter = 0; iter < 100; ++iter) {
        long double mid = (L_Y + R_Y) * 0.5L;
        long double L_X = -1e18L, R_X = 1e18L;
        bool feasible = true;

        for (int i = 0; i < v.size(); ++i) {
            long double D = 2.0L * v[i].y * mid - (long double)v[i].y * v[i].y;

            if (D < 0) {
                feasible = false;
                break;
            }

            long double sqrtD = sqrt(D);
            long double l = v[i].x - sqrtD;
            long double r = v[i].x + sqrtD;

            L_X = max(L_X, l);
            R_X = min(R_X, r);

            if (L_X > R_X) {
                feasible = false;
                break;
            }
        }

        if (feasible && L_X <= R_X) {
            R_Y = mid;
        } else {
            L_Y = mid;
        }
    }
    return R_Y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<point> v(n);
    int P = 0,N = 0;//确认是否可以找到
    for (int i = 0; i < n; i++) {
        cin>>v[i].x>>v[i].y;
        if (v[i].y > 0) {
            P = 1;
        }
        if (v[i].y < 0) {
            N = 1;
        }
    }
    if (P == 1&&N == 1) {
        cout<<-1<<"\n";
        return 0;
    }
    long double ans = round(v);
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}