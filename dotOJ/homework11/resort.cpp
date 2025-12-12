//
// Created by 34021 on 2025/12/11.
//

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct sat {
    ll a;
    ll b;
    bool operator < (const sat& other) const {
        return (b - a) > (other.b - other.a);
    }
};
ll cnt1(int n,int m,vector<pair<ll,ll>> &sat_val) {
    ll ans = 0;
    vector<sat> Sat;
    for (auto i : sat_val) {
        if (i.first >= i.second) {
            ans += i.first;
            n--;
            m--;
        }
        else {
            Sat.push_back({i.first,i.second});
        }
    }
    sort(Sat.begin(),Sat.end());
    for (int i = 0;i < n;i++) {
        if (m - 2 >= n - i - 1) {
            ans += Sat[i].b;
            m -= 2;
        }
        else {
            ans += Sat[i].a;
            m--;
        }
    }
    return ans;
}
ll cnt2(int n,int m,vector<pair<ll,ll>> &sat_val) {
    if (n == 1) {
        return sat_val[0].second;
    }
    ll ans = 0;
    vector<sat> Sat;
    for (auto i : sat_val) {
        Sat.push_back({i.first,i.second});
    }
    vector<int> pos(m,0);
    sort(Sat.begin(),Sat.end());
    for (int i = 0;i < n;i++) {
        if (i == n - 1 && 2 * i <= pos.size() - 1&&pos[2 * i - 1] == 0) {
            if (Sat[i].a + Sat[i - 1].a > Sat[i].b + Sat[i - 1].b) {
                ans = ans - Sat[i - 1].b + Sat[i].a + Sat[i - 1].a;
            }
            else {
                ans += Sat[i].b;
            }
        }
        else if (m - 2 >= n - i - 1) {
            ans += Sat[i].b;
            m -= 2;
            pos[i * 2] = 1;
        }
        else {
            ans += Sat[i].a;
            m--;
        }
    }
    return ans;
}
void solve() {
    int n,m;
    cin >> n >> m;

    vector<pair<ll,ll>> sat_val(n);
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        cin >> sat_val[i].first >> sat_val[i].second;
        if (sat_val[i].first >= sat_val[i].second) {
            cnt++;
        }
    }
    ll ans = 0;
    if (cnt >= 2) {
        ans = cnt1(n,m,sat_val);
    }
    else {
        ans = cnt2(n,m,sat_val);
    }
    cout << ans <<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}