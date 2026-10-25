using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)return head;
    ListNode dummy;
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = head;
    ListNode* third = second;
    while (second != nullptr && second->next != nullptr) {
        third = second->next;
        second->next = third->next;
        third->next = second;
        first->next = third;
        first = second;
        second = second->next;
    }
    return dummy.next;
}
 