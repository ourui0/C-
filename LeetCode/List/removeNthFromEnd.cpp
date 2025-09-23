//
// Created by 34021 on 2025/9/17.
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
//双指针法
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = new ListNode(0);//虚拟头方便操作
    prev -> next = head;
    int count = 0;
    while (fast -> next != nullptr) {
        fast = fast->next;
        count++;
        if (count >= n) {
            prev = prev -> next;
            slow = slow->next;
        }
    }
    if (slow == head) {
        head = head -> next;
    }
    else {
        prev->next = slow->next;
    }
    return head;
}
void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp!=nullptr) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = removeNthFromEnd(head, 5);
    printList(head);

    ListNode* cur = head;
    while(cur!=nullptr) {
        ListNode* temp = cur;
        cur = cur -> next;
        delete temp;
    }
    return 0;
}