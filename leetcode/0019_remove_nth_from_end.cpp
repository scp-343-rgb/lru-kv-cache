using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode dummy;
    dummy.next = head;
    ListNode* left = &dummy;
    ListNode* right = &dummy;
    while (n != 0) {
        right=right->next;
        n--;
    }
    while (right->next != nullptr) {
        right = right->next;
        left = left->next;
    }
    left->next = left->next->next;
    return dummy.next;
}