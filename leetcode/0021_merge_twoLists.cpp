#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (list1 == nullptr) return list2;
    else if (list2 == nullptr) return list1;
    ListNode dummy;
    ListNode* head = &dummy;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val > list2->val) {
            head->next = list2;
            list2 = list2->next;
        }
        else {
            head->next = list1;
            list1 = list1->next;
        }
        head = head->next;
    }
    head->next = list1 ? list1 : list2;
    return dummy.next;
}
int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node4->next = node5;
    node5->next = node6;
    ListNode* res = mergeTwoLists(node1, node4);
    for (;res != nullptr;res = res->next) {
        cout << res->val << " ";
    }
    cout << endl;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    return 0;
}