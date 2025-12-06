//
// Created by 34021 on 2025/12/4.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

struct Edge {
    int u, v;
    ll w;
    bool operator<(Edge const &other) const {
        return w < other.w;
    }
};

ll solve(int l, int r) {
    int Size = r - l + 1;
    ll ans = 0;

    DSU UF(Size);
    vector<Edge> edges;
    edges.reserve(Size * 15);

    for (int step = 1; step <= Size; ++step) {

        int first = ((l + step - 1) / step) * step;
        if (first > r) continue;

        int p = first - l;

        for (int curV = first + step; curV <= r; curV += step) {
            int q = curV - l;
            ll w = 1LL * first * curV / step;
            edges.push_back({p, q, w});
        }
    }

    sort(edges.begin(), edges.end());

    for (auto &e : edges) {
        if (UF.unite(e.u, e.v)) {
            ans += e.w;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r;
    cin >> l >> r;

    ll ans = solve(l, r);
    cout << ans;

    return 0;
}
