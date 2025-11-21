//
// Created by 34021 on 2025/10/10.
//
#include<bits/stdc++.h>
using namespace std;

queue<int> A, B;
vector<pair<char, char>> operations;

void mergeSort(int n) {
    // 归并排序
    int size = 1;
    while (size < n) {
        // 处理所有元素
        int total = n;
        while (total > 0) {
            // 处理一对段
            int left_size = min(size, total);
            total -= left_size;
            int right_size = min(size, total);
            total -= right_size;

            // 将左段移动到B
            for (int i = 0; i < left_size; i++) {
                B.push(A.front());
                A.pop();
                operations.emplace_back('A','B');
            }

            // 如果右段为空，直接处理左段
            if (right_size == 0) {
                for (int i = 0; i < left_size; i++) {
                    A.push(B.front());
                    B.pop();
                    operations.emplace_back('B','A');
                }
                continue;
            }

            // 合并两个段
            int i = 0, j = 0;
            while (i < left_size && j < right_size) {
                if (B.front() <= A.front()) {
                    A.push(B.front());
                    B.pop();
                    operations.emplace_back('B','A');
                    i++;
                } else {
                    A.push(A.front());
                    A.pop();
                    operations.emplace_back('A','A');
                    j++;
                }
            }

            // 处理剩余元素
            while (i < left_size) {
                A.push(B.front());
                B.pop();
                operations.emplace_back('B', 'A');
                i++;
            }

            while (j < right_size) {
                A.push(A.front());
                A.pop();
                operations.emplace_back('A', 'A');
                j++;
            }
        }

        size *= 2;
    }
}

void sort() {
    int n = A.size();
    mergeSort(n);
    cout << operations.size() << '\n';
    for (auto& op : operations) {
        cout << op.first << ' ' << op.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        A.push(x);
    }
    sort();

    // cout << "\n";
    // for (int i = 0; i < N; ++i) {
    //     cout << A.front() << ' ';
    //     A.pop();
    // }
    // cout << '\n';

    return 0;
}