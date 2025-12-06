//
// Created by 34021 on 2025/12/4.
//
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2000;

ll solve(int n,int seed,int p) {
    mt19937 rng(seed);//设置种子

    vector<bitset<MAXN>> adj(n);

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (j == i) {
                adj[i].set(j);
            }
            else {
                unsigned int random = rng();
                if (random % p == 0) {
                    adj[i].set(j);
                }
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (adj[i][j]) {
                adj[i] |= adj[j];
            }
        }
    }
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += (ll)adj[i].count();
    }

    return cnt;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,seed,p;
    cin >> n >> seed >> p;

    ll ans  = solve(n,seed,p);
    cout << ans;
    return 0;
}