//
// Created by 34021 on 2025/12/20.
//
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n,m,c;
    cin >> n >> m >> c;

    vector<vector<ll>> nums(n,vector<ll> (m) );
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> nums[i][j];
        }
    }

    vector<pair<ll,int>> Max(m,{LLONG_MIN,-1});
    vector<vector<ll>> score(m,vector<ll>(n,LLONG_MIN));

    for (int i = 0;i < n;i++) {
        score[0][i] = nums[i][0];
        if (score[0][i] > Max[0].first) {
            Max[0] = {score[0][i],i};
        }
    }

    for (int i = 1;i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (j == Max[i - 1].second) {
                score[i][j] = Max[i - 1].first + nums[j][i];
            }
            else {
                score[i][j] = max(score[i - 1][j] + nums[j][i],Max[i - 1].first + nums[j][i] - c);
            }
            if (score[i][j] > Max[i].first) {
                Max[i] = {score[i][j],j};
            }
        }
    }
    cout << Max[m - 1].first<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}