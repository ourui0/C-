//
// Created by 34021 on 2025/9/26.
//
#include<bits/stdc++.h>
using namespace std;
vector<int> min_heap(200000,INT_MAX);
priority_queue<int> max_heap;
int min_Size = 0;
void push(int x) {
    min_Size++;
    if (empty(max_heap) || x > max_heap.top()) {
        min_heap[min_Size] = x;
    }
    else {
        min_heap[min_Size] = max_heap.top();
        max_heap.pop();
        max_heap.push(x);
    }
    int pos = min_Size;
    // 向上调整 - 时间复杂度 O(log n)
    while (pos > 1) {
        int parent = pos / 2;
        if (min_heap[pos] < min_heap[parent]) {
            // 更新映射
            swap(min_heap[pos], min_heap[parent]);
            pos = parent;
        } else {
            break;
        }
    }
}

void pop() {
    if (min_Size == 0) return;

    // 删除堆顶元素的映射

    // 将最后一个元素移到堆顶
    min_heap[1] = min_heap[min_Size];
    min_heap[min_Size] = INT_MAX;
    min_Size--;

    // 向下调整 - 时间复杂度 O(log n)
    int pos = 1;
    while (pos * 2 <= min_Size) { // 确保有左孩子
        int left = pos * 2;
        int right = pos * 2 + 1;
        int smallest = pos;

        // 找到三个节点中最小的
        if (left <= min_Size && min_heap[left] < min_heap[smallest]) {
            smallest = left;
        }
        if (right <= min_Size && min_heap[right] < min_heap[smallest]) {
            smallest = right;
        }

        if (smallest != pos) {
            // 交换并更新映射
            swap(min_heap[pos], min_heap[smallest]);
            pos = smallest;
        } else {
            break;
        }
    }
}

void DB() {
    cout<<min_heap[1]<<"\n";
    max_heap.push(min_heap[1]);
    pop();
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
            DB();
            while (N[j] == N[j + 1]) {
                j++;
                DB();
            }
            j++;
        }
    }
    return 0;
}