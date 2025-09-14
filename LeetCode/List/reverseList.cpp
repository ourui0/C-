//
// Created by 34021 on 2025/9/15.
//
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* prev = nullptr;
    ListNode* next = current ->next;
    while (current != nullptr) {
        current -> next = prev;
        prev = current;
        current = next;
        if (next != nullptr) {
            next = next->next;
        }
    }
    head = prev;
    return head;
}

// 打印链表函数
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> nullptr" << std::endl;
}

int main() {
    // 手工构建链表 [1,2,6,3,4,5,6]
    // 创建所有节点
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(6);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(4);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(6);

    // 连接节点
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = nullptr; // 最后一个节点的next指向nullptr

    // 头节点
    ListNode* head = node1;

    // 打印链表以验证
    std::cout << "构建的链表: ";
    head = reverseList(head);
    printList(head);

    // 释放内存（在实际应用中很重要）
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}