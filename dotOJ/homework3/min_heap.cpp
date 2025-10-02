//
// Created by 34021 on 2025/9/26.
//
#include<bits/stdc++.h>

using namespace std;

vector<int> min_heap(1000000,INT_MAX);
vector<int> Pos(1000000);//储存第几次插入的值
unordered_map<int, int> value; // 使用unordered_map替代大数组
int Cou = 0;//记录第几次插入
int min_Size = 0;

void push(int x) {
    min_Size++;
    Cou++;
    Pos[Cou] = x;
    value[x] = min_Size; // 使用unordered_map
    min_heap[min_Size] = x;
    int pos = min_Size;

    // 向上调整 - 时间复杂度 O(log n)
    while (pos > 1) {
        int parent = pos / 2;
        if (min_heap[pos] < min_heap[parent]) {
            // 更新映射
            value[min_heap[pos]] = parent;
            value[min_heap[parent]] = pos;
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
    value.erase(min_heap[1]);

    // 将最后一个元素移到堆顶
    min_heap[1] = min_heap[min_Size];
    value[min_heap[1]] = 1; // 更新新堆顶的映射
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
            value[min_heap[pos]] = smallest;
            value[min_heap[smallest]] = pos;
            swap(min_heap[pos], min_heap[smallest]);
            pos = smallest;
        } else {
            break;
        }
    }
}

void decrease(int pos, int k) {
    // 查找第pos次插入的值在堆中的位置
    int heap_pos = value[Pos[pos]];

    // 更新堆中的值
    min_heap[heap_pos] = k;
    value[k] = heap_pos; // 更新映射
    Pos[pos] = k;

    // 向上调整 - 时间复杂度 O(log n)
    int i = heap_pos;
    while (i > 1) {
        int parent = i / 2;
        if (min_heap[i] < min_heap[parent]) {
            value[min_heap[i]] = parent;
            value[min_heap[parent]] = i;
            swap(min_heap[i], min_heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

int main() {
    string s;
    while (cin>>s) {
        if (s == "top") {
            if (min_Size > 0) { // 使用Size判断堆是否为空
                cout<<min_heap[1]<<"\n";
            }
            else {
                cout<<"error"<<"\n";
            }
        }
        else if (s == "size"){
            cout<<min_Size<<"\n";
        }
        else if (s == "push") {
            int x;
            cin>>x;
            push(x);
        }
        else if (s == "pop") {
            if (min_Size > 0) { // 使用Size判断堆是否为空
                pop();
            }
        }
        else if (s == "decrease") {
            int i,k;
            cin>>i;
            cin>>k;
            decrease(i,k);
        }
    }
}