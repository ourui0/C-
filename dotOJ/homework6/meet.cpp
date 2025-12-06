//
// Created by 34021 on 2025/11/2.
//
#include<bits/stdc++.h>
using namespace std;
struct X {
    long long x;
    int y = 0;
    long long v;
};
struct Y {
    int x = 0;
    long long y;
    long long v;
};
int solve(vector<X> X,vector<Y> Y,int n,int m) {
    int cnt = 0;
    unordered_map<long long,int> map;
    for (int i = 0; i < n;i++) {
        if (X[i].v > 0) {
            long long index = X[i].v * X[i].x;
            map[index]++;
        }
    }
    for (int i = 0;i < m;i++) {
        if (Y[i].v > 0) {
            long long index = Y[i].v * Y[i].y;
            if (map.contains(index)) {
                cnt+=map[index];
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >>m;

    vector<X> X_arr(n);
    for (int i = 0;i < n;i++) {
        cin >> X_arr[i].x >>X_arr[i].v;
    }
    vector<Y> Y_arr(m);
    for (int i = 0; i < m;i++) {
        cin >> Y_arr[i].y >> Y_arr[i].v;
    }

    int ans = solve(X_arr,Y_arr,n,m);

    cout << ans;

    return 0;
}