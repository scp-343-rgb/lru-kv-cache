#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    int cnt1 = 0, cnt2 = 0;
    ListNode* pa = headA;
    ListNode* pb = headB;
    while (pa != nullptr) {
        cnt1++;
        pa = pa->next;
    }
    while (pb != nullptr) {
        cnt2++;
        pb = pb->next;
    }
    int diff = cnt1 - cnt2;
    diff = std::abs(diff);
    if (cnt1 > cnt2) {
        while (diff != 0) {
            headA = headA->next;
            diff--;
        }
    }
    else if (cnt2 > cnt1) {
        while (diff != 0) {
            headB = headB->next;
            diff--;
        }
    }
    while (headA != nullptr) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}
int main()
{
    return 0;
}