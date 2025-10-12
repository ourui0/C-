//
// Created by 34021 on 2025/10/10.
//
#include<bits/stdc++.h>
using namespace std;

queue<int> A, B;
vector<pair<char, char>> operations;

void merge(int leftSize, int rightSize, queue<int>& src, queue<int>& dst) {
    // 将src队列中要合并的rightSize个元素暂存到dst队列后面
    for (int i = 0; i < rightSize; i++) {
        dst.push(src.front());
        src.pop();
        char from = (&src == &A) ? 'A' : 'B';
        char to = (&dst == &A) ? 'A' : 'B';
        operations.emplace_back(from, to);
    }

    // 现在src队列为空，dst队列包含leftSize个有序元素和rightSize个有序元素
    // 合并这两个有序段到src队列
    int i = 0, j = 0;
    while (i < leftSize && j < rightSize) {
        if (dst.front() <= dst.back()) {
            // 取dst前面的元素（来自第一个有序段）
            src.push(dst.front());
            dst.pop();
            char from = (&dst == &A) ? 'A' : 'B';
            char to = (&src == &A) ? 'A' : 'B';
            operations.emplace_back(from, to);
            i++;
        } else {
            // 取dst后面的元素（来自第二个有序段）
            // 需要先把前面的元素移到后面去访问后面的元素
            dst.push(dst.front());
            dst.pop();
            char from = (&dst == &A) ? 'A' : 'B';
            char to = (&dst == &A) ? 'A' : 'B';
            operations.emplace_back(from, to);

            // 现在后面的元素到了前面
            src.push(dst.front());
            dst.pop();
            from = (&dst == &A) ? 'A' : 'B';
            to = (&src == &A) ? 'A' : 'B';
            operations.emplace_back(from, to);
            j++;
        }
    }

    // 处理剩余元素
    while (i < leftSize) {
        src.push(dst.front());
        dst.pop();
        char from = (&dst == &A) ? 'A' : 'B';
        char to = (&src == &A) ? 'A' : 'B';
        operations.emplace_back(from, to);
        i++;
    }

    while (j < rightSize) {
        // 把前面的元素移到后面去访问后面的元素
        dst.push(dst.front());
        dst.pop();
        char from = (&dst == &A) ? 'A' : 'B';
        char to = (&dst == &A) ? 'A' : 'B';
        operations.emplace_back(from, to);

        src.push(dst.front());
        dst.pop();
        from = (&dst == &A) ? 'A' : 'B';
        to = (&src == &A) ? 'A' : 'B';
        operations.emplace_back(from, to);
        j++;
    }
}

void mergeSort(int n, queue<int>& src, queue<int>& dst) {
    if (n <= 1) return;

    int leftSize = n / 2;
    int rightSize = n - leftSize;

    // 将前半部分移到dst队列
    for (int i = 0; i < leftSize; i++) {
        dst.push(src.front());
        src.pop();
        char from = (&src == &A) ? 'A' : 'B';
        char to = (&dst == &A) ? 'A' : 'B';
        operations.emplace_back(from, to);
    }

    // 递归排序两个部分
    mergeSort(leftSize, dst, src);
    mergeSort(rightSize, src, dst);

    // 合并两个有序段
    merge(leftSize, rightSize, src, dst);
}

void sort() {
    int n = A.size();
    mergeSort(n, A, B);
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

    cout << "\n";
    for (int i = 0; i < N; ++i) {
        cout << A.front() << ' ';
        A.pop();
    }
    cout << '\n';

    return 0;
}