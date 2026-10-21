#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
    ListNode* first = nullptr;
    ListNode* second = head;
    if (second == nullptr || second->next == nullptr) return head;
    ListNode* third = second->next;
    while (third != nullptr) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    return first;
}
int main()
{
    ListNode* q = new ListNode(2);
    ListNode* head = new ListNode(1, q);
    ListNode* p = reverseList(head);
    cout << "[";
    while (p != nullptr) {
        cout << p->val << ",";
        p = p->next;
    }
    cout << "]";
    delete q;
    delete head;
    return 0;
}