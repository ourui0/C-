//
// Created by 34021 on 2025/12/1.
//
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

struct Edge {
    int u, v;
    ld w;
    Edge(int U, int V, ld W): u(U), v(V), w(W) {}
    // 使用更稳健的比较，考虑浮点误差
    bool operator<(const Edge& other) const {
        if (abs(w - other.w) > 1e-12) return w < other.w;
        // 如果权重非常接近，按顶点编号排序以确保稳定性
        if (u != other.u) return u < other.u;
        return v < other.v;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

ld weight(int ax, int bx) {
    ld dx = (ld)ax - (ld)bx;
    return sqrtl(dx * dx + (ld)bx * bx);
}

void solve(vector<int> &a, vector<int> &b, int n, int m) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<Edge> edges;
    edges.reserve(2 * (n + m) + 10 * (n + m));  // 预分配空间

    // 添加 l1 内部的边
    for (int i = 0; i < n - 1; ++i) {
        edges.push_back({i, i + 1, (ld)abs(a[i] - a[i + 1])});
    }

    // 添加 l2 内部的边
    for (int i = 0; i < m - 1; ++i) {
        edges.push_back({n + i, n + i + 1, abs(b[i] - b[i + 1]) * sqrtl(2.0L)});
    }

    int k = 3;  // 可以尝试3-5

    for (int i = 0; i < n; ++i) {
        // 使用更精确的计算
        ld target = (ld)a[i] / 2.0L;
        int pos = lower_bound(b.begin(), b.end(), target) - b.begin();

        for (int d = -k; d <= k; ++d) {
            int j = pos + d;
            if (j >= 0 && j < m) {
                edges.push_back({i, n + j, weight(a[i], b[j])});
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int target = b[i];
        int pos = lower_bound(a.begin(), a.end(), target) - a.begin();

        for (int d = -k; d <= k; ++d) {
            int j = pos + d;
            if (j >= 0 && j < n) {
                edges.push_back({j, n + i, weight(a[j], b[i])});
            }
        }
    }

    // 运行 Kruskal
    sort(edges.begin(), edges.end());
    DSU dsu(n + m);
    ld total = 0.0L;
    int cnt = 0;

    for (const Edge& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            ++cnt;
            if (cnt == n + m - 1) break;
        }
    }

    cout << fixed << setprecision(11) << (double)total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<int> l1(n);//记录l1横坐标
    for (int i = 0; i < n;i++) {
        cin >> l1[i];
    }

    vector<int> l2(m);//记录l2横坐标
    for (int i = 0; i < m;i++) {
        cin >> l2[i];
    }
    solve(l1,l2,n,m);
    return 0;
}