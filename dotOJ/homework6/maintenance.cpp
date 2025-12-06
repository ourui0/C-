//
// Created by 34021 on 2025/11/2.
//
#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
struct line {
    int l, r;
    line(int l, int r) : l(l), r(r) {}
};
struct Compare {
    bool operator()(const line& a, const line& b) const {
        return a.l < b.l;
    }
};
set<line,Compare> Set;
void op_A(int l,int r) {
    int removed = 0;
    vector<set<line, Compare>::iterator> Remove;

    if (!Set.empty()) {
        auto it = Set.upper_bound(line(r, r));
        if (it != Set.begin()) {
            it--;

            while (true) {
                if (max(it->l, l) <= min(it->r, r)) {
                    Remove.push_back(it);
                    removed++;
                    cnt--;
                }

                if (it == Set.begin()) {
                    break;
                }

                auto prev_it = it;
                prev_it--;

                if (prev_it->r < l) {
                    break;
                }

                it = prev_it;
            }
        }
    }

    for (auto it : Remove) {
        Set.erase(it);
    }

    Set.insert(line(l, r));
    cnt++;
    cout << removed <<'\n';
}
void op_B() {
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l,r;
            cin >> l >> r;
            op_A(l,r);
        }
        else {
            op_B();
        }
    }
    return 0;
}