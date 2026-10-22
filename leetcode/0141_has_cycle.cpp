#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode* head)
{
    bool found = false;
    ListNode* right = head;
    ListNode* left = head;
    if (head == nullptr) return found;
    while (right != nullptr && right->next != nullptr) {
        left = left->next;
        right = right->next->next;
        if (left == right) {
            found = true;
            return found;
        }
    }
    return found;
}
int main()
{
    ListNode* head = new ListNode(3);
    ListNode* first = new ListNode(2);
    ListNode* second = new ListNode(0);
    ListNode* third = new ListNode(-4);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = second;
    cout << hasCycle(head) << endl;
    delete head;
    delete first;
    delete second;
    delete third;
    return 0;
}