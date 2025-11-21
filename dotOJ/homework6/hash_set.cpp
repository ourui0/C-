//
// Created by 34021 on 2025/10/31.
//
#include<bits/stdc++.h>
using namespace std;
struct Node {
    long long key;
    long long value;
    Node* next;
    Node(long long k, long long v) : key(k), value(v), next(nullptr) {}
};
long long cnt = 0;//记录查找存在次数
long long Size = 0;//记录数量
vector<Node*> table;
long long capacity = 10007; // 使用质数减少冲突
// 哈希函数
long long hash_function(long long value) {
    // 处理负数，确保索引为正
    long long positive_value = (value < 0) ? -value : value;
    return positive_value % capacity;
}
void init_table() {
    table.resize(capacity, nullptr);
    Size = 0;
    cnt = 0;
}
bool Find(long long x) {
    long long value_to_find = x;
    long long index = hash_function(value_to_find);

    Node* current = table[index];
    while (current != nullptr) {
        if (current->value == value_to_find) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void Insert(long long x) {
    for (int i = 1; i <= 1000; i++) {
        long long value = i * x; // value = i * x
        long long index = hash_function(value); // 使用value计算哈希索引

        // 检查是否已存在
        bool exists = false;
        Node* current = table[index];
        while (current != nullptr) {
            if (current->value == value) {
                exists = true;
                break;
            }
            current = current->next;
        }

        // 如果不存在则插入
        if (!exists) {
            long long key = Size; // key = 当前的Size
            Node* new_node = new Node(key, value);
            new_node->next = table[index];
            table[index] = new_node;
            Size++;
        }
    }
}
void clear_table() {
    for (long long i = 0; i < capacity; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
    Size = 0;
    cnt = 0;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        init_table();
        int n;
        cin >> n;
        for (int i = 0;i < n;i++) {
            string s;
            cin>>s;
            if (s == "insert") {
                long long x;
                cin >> x;
                Insert(x);
            }
            else {
                long long x;
                cin >> x;
                if (Find(x)) {
                    cnt++;
                }
            }
        }
        cout << Size <<' '<<cnt<<'\n';
        clear_table();
    }
    return 0;
}