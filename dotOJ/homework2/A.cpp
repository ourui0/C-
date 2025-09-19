//
// Created by 34021 on 2025/9/19.
//
#include <bits/stdc++.h>
using namespace std;

long long Count = 0;  //全局计数器

void merge(vector<int>& a, vector<int>& tmp, int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            Count += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r)   tmp[k++] = a[j++];
    for (int t = l; t <= r; ++t) a[t] = tmp[t];
}

void mergeSort(vector<int>& a, vector<int>& tmp, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(a, tmp, l, mid);
    mergeSort(a, tmp, mid + 1, r);
    merge(a, tmp, l, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> mp(n), pos(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> mp[i];
            pos[mp[i]] = i;
        }

        vector<int> tmp(n);
        Count = 0;
        mergeSort(mp, tmp, 0, n - 1);

        cout << Count << '\n';
    }
    return 0;
}