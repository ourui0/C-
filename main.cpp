#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAXN = 300005;
const int MAXM = 500005;

vector<pair<int, int>> adj[MAXN];
int dfn[MAXN];
int low[MAXN];
int parent[MAXN];
int timer;

bool is_used[MAXM];
ll bridge_cnt;
vector<int> cycle_len;

ll compute(int k) {
    ll res = 1;
    for (int i = 0; i < k; ++i) {
        res = (res * 2) % MOD;
    }
    return res;
}

void Tarjan(int u, int p) {
    dfn[u] = low[u] = ++timer;
    parent[u] = p;

    for(auto& edge : adj[u]) {
        int v = edge.first;
        int edge_index = edge.second; //唯一标识
        if(v == p) continue;  //自环，需要跳过

        if(dfn[v]) { // 后向边
            low[u] = min(low[u], low[v]); //u可以到达v，应该给u去二者之间的最小时间戳
            if(dfn[v] < dfn[u]) { //先访问的v，意味着这是一个环
                // if(is_used[edge_index]) continue;
                // is_used[edge_index] = true;
                //因为题目中说了，一条边只会在一个环里面，所以这一段不需要
                int small_cycle_len = 1; //u,v这条边
                int curr = u;
                while(curr != v) {
                    curr = parent[curr];
                    small_cycle_len++;
                }
                cycle_len.push_back(small_cycle_len);
            }
        } else {
            Tarjan(v, u); //对这个新的点，也就是v进行tarjan算法，得到这个对应的访问时间戳，和最小时间戳
            //在这个时候v的所有子节点以及v子节点的子节点都应已经访问玩，也就是说这个时候v的low和dfn都不会再改变了
            //tip：在这个时候，我们并不知道这个是环边还是桥
            low[u] = min(low[u], low[v]); //更新一下low[u]
            //如果此时的u的最小时间戳还是小于v的话，那就只能是桥
            if(low[v] > low[u]) {
                bridge_cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            timer = 0;
            bridge_cnt = 0;
            cycle_len.clear();
            Tarjan(i, 0);
            ll temp_ans = 1;

            temp_ans = (temp_ans * compute(bridge_cnt)) % MOD;

            for(int len : cycle_len) {
                ll cycle_pow = compute(len);
                ll cycle_contrib = (cycle_pow - 1 + MOD) % MOD;
                temp_ans = (temp_ans * cycle_contrib) % MOD;
            }

            ans = (ans * temp_ans) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}