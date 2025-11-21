//
// Created by 34021 on 2025/11/7.
//
#include<bits/stdc++.h>
using namespace std;
class UnionFind {
private:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

public:
    // 构造函数，初始化n个元素
    UnionFind() = default;

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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int l = n;
        UnionFind uf;
        bool index = true;
        deque<vector<int>> Assert;
        while (n--) {
            vector<int> temp(3);
            cin >> temp[0] >> temp[1] >> temp[2];
            if (temp[2] == 1) {
                Assert.emplace_front(temp);
            }
            else {
                Assert.emplace_back(temp);
            }
        }
        for (int i = 0; i < l;i++) {
            vector<int> temp = Assert.front();
            if (temp[2] == 1) {
                uf.unite(temp[0],temp[1]);
                Assert.pop_front();
            }
            else {
                if (uf.connected(temp[0],temp[1])) {
                    index = false;
                    break;
                }
                Assert.pop_front();
            }
        }
        cout << (index ? "YES" : "NO") << '\n';
    }
    return 0;
}