#include<iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // 计算行前缀和（纵向前缀和）v: 大小为n
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i] += matrix[i][j];
        }
        if (i != 0) {
            v[i] += v[i - 1];
        }
    }

    // 计算列前缀和（横向前缀和）h: 大小为m
    vector<int> h(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            h[j] += matrix[i][j];
        }
        if (j != 0) {
            h[j] += h[j - 1];
        }
    }

    int min_row_cut = INT_MAX; // 行切割的最小差异
    int min_col_cut = INT_MAX; // 列切割的最小差异

    // 行切割：循环从0到n-2
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(v[n - 1] - 2 * v[i]);
        if (diff < min_row_cut) {
            min_row_cut = diff;
        }
    }

    // 列切割：循环从0到m-2
    for (int j = 0; j < m - 1; j++) {
        int diff = abs(h[m - 1] - 2 * h[j]);
        if (diff < min_col_cut) {
            min_col_cut = diff;
        }
    }

    int ans = min(min_row_cut, min_col_cut);
    cout << ans << endl;
    return 0;
}