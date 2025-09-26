//
// Created by 34021 on 2025/9/26.
//
#include<bits/stdc++.h>
using namespace std;
vector<int> heap(1000000,INT_MAX);
int Size = 0;

void push(int x) {
    Size++;
    heap[Size] = x;
    int pos = Size;

    // 向上调整 - 时间复杂度 O(log n)
    while (pos > 1) {
        int parent = pos / 2;
        if (heap[pos] < heap[parent]) {
            // 更新映射
            swap(heap[pos], heap[parent]);
            pos = parent;
        } else {
            break;
        }
    }
}

void pop() {
    if (Size == 0) return;

    // 删除堆顶元素的映射

    // 将最后一个元素移到堆顶
    heap[1] = heap[Size];
    heap[Size] = INT_MAX;
    Size--;

    // 向下调整 - 时间复杂度 O(log n)
    int pos = 1;
    while (pos * 2 <= Size) { // 确保有左孩子
        int left = pos * 2;
        int right = pos * 2 + 1;
        int smallest = pos;

        // 找到三个节点中最小的
        if (left <= Size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right <= Size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != pos) {
            // 交换并更新映射
            swap(heap[pos], heap[smallest]);
            pos = smallest;
        } else {
            break;
        }
    }
}

void DB() {
    cout<<heap[1]<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin>>m>>n;

    vector<int> M(200000);
    vector<int> N(200000);
    for (int i = 0; i < m;i++) {
        cin>>M[i];
    }

    for (int i = 0;i < n;i++) {
        cin>>N[i];
    }
    int j = 0;
    for (int i = 0;i < m;i++) {
        push(M[i]);
        if (j == n) {
            break;
        }
        if (i + 1 == N[j]) {
            j++;
            DB();
            i--;
        }
    }
    return 0;
}