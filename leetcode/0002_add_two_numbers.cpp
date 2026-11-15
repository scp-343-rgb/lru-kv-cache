using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* p = l1, * q = l2;
    int len1 = 0, len2 = 0, carry = 0;
    while (p != nullptr) {
        len1++;
        p = p->next;
    }
    while (q != nullptr) {
        len2++;
        q = q->next;
    }
    p = l1, q = l2;
    ListNode dummy(0);
    ListNode* tail = &dummy;
    if (len1 > len2) {
        while (q != nullptr) {
            int sum = p->val + q->val + carry;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = node;
            tail = tail->next;
            p = p->next;
            q = q->next;
        }
        while (p != nullptr) {
            int sum = p->val + carry;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = node;
            tail = tail->next;
            p = p->next;
        }
    }
    else {
        while (p != nullptr) {
            int sum = p->val + q->val + carry;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = node;
            tail = tail->next;
            p = p->next;
            q = q->next;
        }
        while (q != nullptr) {
            int sum =  q->val + carry;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = node;
            tail = tail->next;
            q = q->next;
        }
    }
    if (carry == 1) {
        ListNode* node = new ListNode(carry);
        tail->next = node;
    }
    return dummy.next;
}