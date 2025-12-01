#include<bits/stdc++.h>
using namespace std;

struct Node {
    long long value;
    int prev, next;
    bool removed;
};

vector<Node> houses;
vector<int> heap;  // 存储房屋索引
vector<int> heap_pos;  // 房屋索引在堆中的位置
int heap_size = 0;

inline bool compare(int a, int b) {
    if (houses[a].value != houses[b].value)
        return houses[a].value < houses[b].value;
    return a < b;
}

inline void heap_swap(int i, int j) {
    swap(heap[i], heap[j]);
    heap_pos[heap[i]] = i;
    heap_pos[heap[j]] = j;
}

// 向上调整
void heapify_up(int pos) {
    while (pos > 1 && compare(heap[pos], heap[pos/2])) {
        heap_swap(pos, pos/2);
        pos /= 2;
    }
}

// 向下调整
void heapify_down(int pos) {
    while (pos * 2 <= heap_size) {
        int left = pos * 2;
        int right = pos * 2 + 1;
        int smallest = pos;

        if (compare(heap[left], heap[smallest]))
            smallest = left;
        if (right <= heap_size && compare(heap[right], heap[smallest]))
            smallest = right;

        if (smallest != pos) {
            heap_swap(pos, smallest);
            pos = smallest;
        } else {
            break;
        }
    }
}

void push(int idx) {
    heap[++heap_size] = idx;
    heap_pos[idx] = heap_size;
    heapify_up(heap_size);
}

void pop() {
    if (heap_size == 0) return;

    heap_pos[heap[1]] = 0;  // 标记为已删除
    if (heap_size > 1) {
        heap[1] = heap[heap_size];
        heap_pos[heap[1]] = 1;
        heapify_down(1);
    }
    heap_size--;
}

void mark_increase(int idx, long long k) {
    if (houses[idx].removed) return;
    houses[idx].value += k;
    // 标记需要堆调整，但不在循环中立即调整
    heapify_down(heap_pos[idx]);
    heapify_up(heap_pos[idx]);
}

void print(int n) {
    // 直接遍历链表输出，避免vector操作
    int start = 1;
    while (start <= n && houses[start].removed) {
        start++;
    }

    if (start > n) {
        cout << "0 0\n";
        return;
    }

    vector<long long> result;
    result.reserve(n);  // 预分配空间

    int current = start;
    while (current <= n && current != 0) {
        if (!houses[current].removed) {
            result.push_back(houses[current].value);
        }
        current = houses[current].next;
    }

    // 一次性输出
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 预分配内存
    houses.resize(n + 2);
    heap.resize(n + 2);
    heap_pos.resize(n + 2, 0);

    // 初始化
    for (int i = 1; i <= n; i++) {
        cin >> houses[i].value;
        houses[i].prev = i - 1;
        houses[i].next = i + 1;
        houses[i].removed = false;
        push(i);
    }
    houses[1].prev = 0;
    houses[n].next = n + 1;

    while (k-- && heap_size > 0) {
        int top_idx = heap[1];
        long long top_value = houses[top_idx].value;

        if (houses[top_idx].removed) {
            pop();
            k++;  // 这次操作无效，补偿一次
            continue;
        }

        houses[top_idx].removed = true;

        int prev_idx = houses[top_idx].prev;
        int next_idx = houses[top_idx].next;

        // 更新链表
        if (prev_idx >= 1 && prev_idx <= n)
            houses[prev_idx].next = next_idx;
        if (next_idx >= 1 && next_idx <= n)
            houses[next_idx].prev = prev_idx;

        // 增加相邻房屋怨气值
        if (prev_idx >= 1 && prev_idx <= n && !houses[prev_idx].removed)
            mark_increase(prev_idx, top_value);
        if (next_idx >= 1 && next_idx <= n && !houses[next_idx].removed)
            mark_increase(next_idx, top_value);

        pop();
    }

    print(n);
    return 0;
}