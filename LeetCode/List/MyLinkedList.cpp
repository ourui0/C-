//
// Created by 34021 on 2025/9/14.
//
#include<iostream>
using namespace std;
class MyLinkedList {
private:
    // 定义链表节点结构
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* head;  // 头指针
    int size;        // 链表长度

public:
    // 构造函数
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    // 获取指定位置的元素
    int get(int index) {
        if (index >= size || index < 0)return -1;

        ListNode* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp->val;
    }

    // 在头部添加节点
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node -> next = head;
        head = node;
        size++;
    }

    // 在尾部添加节点
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* temp = head;
        for (int i = 0; temp -> next; i++) temp = temp->next;
        temp->next = node;
        node -> next = nullptr;
        size++;
    }

    // 在指定位置插入节点
    void addAtIndex(int index, int val) {
        if (index >= size || index < 0)return;
        ListNode* node = new ListNode(val);
        ListNode* temp = head;
        for (int i = 1; i < index; i++) temp = temp->next;
        node -> next = temp->next;
        temp->next = node;
        size++;
    }

    // 删除指定位置的节点
    void deleteAtIndex(int index) {
        if (index >= size || index < 0)return;
        ListNode* temp = head;
        for (int i = 1; i < index; i++) temp = temp->next;
        ListNode* del = temp->next ->next;
        delete temp -> next;
        temp->next = del;
    }

    // 析构函数，释放所有节点内存
    ~MyLinkedList() {
        ListNode* temp = head;
        while (temp) {
            ListNode* cur = temp;
            temp = temp->next;
            delete cur;
        }
    }
};
int main() {
    MyLinkedList* list = new MyLinkedList();
    list->addAtHead(1);
    list->addAtTail(3);
    list->addAtIndex(1, 2);    // 链表变为 1->2->3
    cout << list->get(1) << endl; // 返回 2
    list->deleteAtIndex(1);    // 删除索引为1的节点，链表变为 1->3
    cout << list->get(1) << endl; // 返回 3

    delete list; // 释放链表内存
    return 0;
}