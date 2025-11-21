//
// Created by 34021 on 2025/11/7.
//
#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // 构造函数，初始化n个元素
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 查找操作，带路径压缩
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并操作，带按秩合并
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        // 按秩合并
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // 检查两个元素是否在同一个集合
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

string F(string s1,string s2,string s3) {
    UnionFind uf(26);
    int n = s1.size();
    for (int i = 0; i < n;i++) {
        int idx1 = s1[i] - 'a';
        int idx2 = s2[i] - 'a';
        uf.unite(idx1,idx2);
    }
    for (int i = 0;i < n;i++) {
        int idx1 = s1[i] - 'a';
        int idx3 = s3[i] - 'a';
        if (!uf.connected(idx1,idx3)) {
            return "YES";
        }
    }
    return "NO";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;

        string ans = F(s1,s2,s3);

        cout << ans << '\n';
    }
    return 0;
}