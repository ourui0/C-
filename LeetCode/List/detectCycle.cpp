//
// Created by 34021 on 2025/9/17.
//
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            ListNode *P = head;
            while(true) {
                if(slow == P) {
                    return slow;
                }
                slow = slow->next;
                P = P->next;
            }
        }
    }
    return nullptr;
}
int main() {
    ListNode *head = new ListNode(1);
    ListNode *head2 = new ListNode(2);
    head->next = head2;
    head2->next = head;
    ListNode *head3 = detectCycle(head);
    cout<<head3->val<<endl;
    return 0;
}