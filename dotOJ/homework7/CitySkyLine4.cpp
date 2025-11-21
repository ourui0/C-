//
// Created by 34021 on 2025/11/7.
//
#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        count = n;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getCount() {
        return count;
    }
};

bool check(int D, int n, int m, vector<vector<int>>& heights, vector<vector<int>>& spots) {
    UnionFind uf(n * m);

    // 合并相邻格子（如果海拔差 <= D）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;

            // 检查右边邻居
            if (j + 1 < m && abs(heights[i][j] - heights[i][j + 1]) <= D) {
                uf.unite(idx, i * m + j + 1);
            }

            // 检查下边邻居
            if (i + 1 < n && abs(heights[i][j] - heights[i + 1][j]) <= D) {
                uf.unite(idx, (i + 1) * m + j);
            }
        }
    }

    // 收集所有景点
    vector<int> spotIndices;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spots[i][j] == 1) {
                spotIndices.push_back(i * m + j);
            }
        }
    }

    // 如果景点数为0，直接返回true
    if (spotIndices.empty()) return true;

    // 检查所有景点是否连通
    int root = uf.find(spotIndices[0]);
    for (int i = 1; i < spotIndices.size(); i++) {
        if (uf.find(spotIndices[i]) != root) {
            return false;
        }
    }
    return true;
}

int solve(int n, int m, vector<vector<int>>& heights, vector<vector<int>>& spots) {
    // 如果没有景点或只有1个景点，直接返回0
    bool hasSpot = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spots[i][j] == 1) {
                hasSpot = true;
                break;
            }
        }
        if (hasSpot) break;
    }
    if (!hasSpot) return 0;

    // 找到海拔的最小值和最大值
    int minH = INT_MAX, maxH = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            minH = min(minH, heights[i][j]);
            maxH = max(maxH, heights[i][j]);
        }
    }

    // 二分查找
    int left = 0, right = maxH - minH;
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid, n, m, heights, spots)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> heights[i][j];
        }
    }

    vector<vector<int>> spots(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spots[i][j];
        }
    }

    int ans = solve(n, m, heights, spots);
    cout << ans << endl;

    return 0;
}