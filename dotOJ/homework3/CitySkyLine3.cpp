#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    long long use;
    long long i;
    bool operator<(const Node &other) const {
        if (use != other.use) return use > other.use;
        return i > other.i;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    vector<long long> m(n);

    // 完全预处理
    long long total_a = 0;
    long long total_m = 0;
    priority_queue<Node> m_set;

    // 初始化
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total_a += a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> m[i];
        total_m += m[i];
        m_set.push({m[i],i});
    }

    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            long long i, b;
            cin >> i >> b;
            i--;
            total_a = total_a - a[i] + b;
            a[i] = b;
        }
        else if (x == 2) {
            long long i, b;
            cin >> i >> b;
            i--;

            // 更新total_m
            total_m = total_m - m[i] + b;
            m[i] = b;

            m_set.push({b, i});
        }
        else if (x == 3) {
            while (!m_set.empty() && m_set.top().use != m[m_set.top().i]) {
                m_set.pop();
            }
            long long S = total_a;
            long long M = total_m;
            long long min_m = m_set.top().use;
            long long A = M - n;

            if (S < M) {
                cout << 0 << "\n";
            }
            else if (A == 0) {
                cout << -1 << "\n";
            }
            else if (min_m == 1) {
                cout << (S-M)/A + 1 << "\n";
            }
            else {
                long long V = S - M;
                int days = 0;
                while (V >= 0) {
                    days++;
                    V = V / min_m - A;
                }
                cout << days << "\n";
            }
        }
    }
    return 0;
}