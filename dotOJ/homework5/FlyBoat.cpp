//
// Created by 34021 on 2025/10/18.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll r_w;
ll l_w;

int QuickSelect(vector<pair<int, ll>> &children, int left, int right, ll l_sum, ll r_sum, ll w_sum) {
    if (left > right) return -1;

    int random = left + rand() % (right - left + 1);
    swap(children[random], children[right]);

    int pivot = children[right].first;
    ll pivot_weight = children[right].second;

    int index = left;
    ll current_l_sum = 0;

    for (int i = left; i < right; i++) {
        if (children[i].first < pivot) {
            swap(children[i], children[index]);
            current_l_sum += children[index].second;
            index++;
        }
    }

    swap(children[index], children[right]);

    ll total_l = l_sum + current_l_sum;
    ll total_r = w_sum - total_l - pivot_weight;

    if (total_l < l_w && total_r <= r_w) {
        return index;
    }

    if (total_l >= l_w) {
        return QuickSelect(children, left, index - 1, l_sum, total_r + pivot_weight, w_sum);
    } else {
        return QuickSelect(children, index + 1, right, total_l + pivot_weight, r_sum, w_sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 设置随机种子
    srand(time(0));

    int N;
    cin >> N;

    vector<pair<int, ll>> children; // 存储编号和体重
    ll w_sum = 0;

    for (int i = 0; i < N; i++) {
        int x;
        ll weight;
        cin >> x >> weight;
        children.push_back({x, weight});
        w_sum += weight;
    }

    l_w = w_sum / 2;
    if (w_sum % 2 == 0) {
        r_w = w_sum / 2;
    } else {
        r_w = w_sum / 2 + 1;
    }

    int result = QuickSelect(children, 0, N - 1, 0, 0, w_sum);

    if (result != -1) {
        cout << children[result].first << '\n';
    }

    return 0;
}