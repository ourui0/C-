# 链表
对于下述代码
```c++
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next; // 在循环内定义next，避免nullptr访问
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
```
如果调用方式为
```c++
head = reverseList(head);
```
能正常工作，但如果调用方式为
```c++
reverseList(head);
```
无法正常工作
只调用reverseList(head);而不赋值，函数确实会反转链表
（即改变节点之间的链接关系）， 但外部的head指针仍然指向
原始的头节点。在反转后，原始头节点变成了尾节点， 其next指
针为nullptr，因此从外部head开始遍历链表只能访问到一个节点
（即原始头节点）， 无法访问整个反转后的链表。

自己手搓的链表遍历时在写退出条件时，可以写一个while（true），在出现
考虑边界情况，在数据更新前，该退出时break；防止下面数据更新时出现报错