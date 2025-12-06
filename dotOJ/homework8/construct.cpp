//
// Created by 34021 on 2025/11/16.
//
#include<bits/stdc++.h>
using namespace std;

struct node {
    int id;
    int degree;
};

bool cmp(const node &a, const node &b) {
    return a.degree > b.degree;
}

int construct(int n, vector<node> &nodes, vector<vector<int> > &edges) {
    int total_degree = 0;
    for (int i = 0; i < n; i++) {
        total_degree += nodes[i].degree;
    }
    if (total_degree % 2 != 0) {
        return -1;
    }

    int cnt = 0;

    while (true) {
        sort(nodes.begin(), nodes.end(), cmp);

        if (nodes[0].degree == 0) break;

        int u = 0;

        while (nodes[u].degree > 0) {
            // 寻找可以连接的节点
            bool found = false;

            // 先尝试连接其他节点
            for (int v = u + 1; v < n; v++) {
                if (nodes[v].degree > 0) {
                    nodes[u].degree--;
                    nodes[v].degree--;
                    edges.push_back({nodes[u].id, nodes[v].id});
                    cnt++;
                    found = true;
                    break;
                }
            }

            if (!found && nodes[u].degree >= 2) {
                nodes[u].degree -= 2;
                edges.push_back({nodes[u].id, nodes[u].id});
                cnt++;
                found = true;
            }

            if (!found) {
                return -1;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<node> nodes(n);

    for (int i = 0; i < n; i++) {
        nodes[i].id = i + 1;
        cin >> nodes[i].degree;
    }

    vector<vector<int> > edges;
    int cnt = construct(n, nodes, edges);


    cout << cnt << '\n';

    if (cnt != -1) {
        for (int i = 0; i < cnt; i++) {
            cout << edges[i][0] << ' ' << edges[i][1] << '\n';
        }
    }

    return 0;
}
