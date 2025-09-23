//
// Created by 34021 on 2025/9/17.
//
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    int countA = 0, countB = 0;
    while (p != NULL) {
        countA++;
        p = p -> next;
    }
    while (q != NULL) {
        countB++;
        q = q -> next;
    }
    if (countA > countB) {
        int temp = countA - countB,count = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while (temp1 != NULL && temp2 != NULL) {
            count++;
            temp1 = temp1 -> next;
            if (count > temp) {
                temp2 = temp2 -> next;
            }
            if (temp2 == temp1) {
                return temp1;
            }
        }
    }
    else {
        int temp = countB - countA,count = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while (temp1 != NULL && temp2 != NULL) {
            count++;
            temp1 = temp1 -> next;
            if (count > temp) {
                temp2 = temp2 -> next;
            }
            if (temp2 == temp1) {
                return temp1;
            }
        }
    }
    return NULL;
}
int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    ListNode *node7 = new ListNode(10);
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node7 -> next = node5;
    cout << getIntersectionNode(node1, node7) -> val << endl;
    return 0;
}