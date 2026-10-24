#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {

    }
    ListNode(int x, ListNode* n) :val(x), next(n) {

    }
};
bool isPalindrome(ListNode* head)
{
    ListNode* left = head;
    ListNode* right = head;
    while (right != nullptr && right->next != nullptr) {
        left = left->next;
        right = right->next->next;
    }
    ListNode* first = nullptr;
    ListNode* second = left;
    ListNode* third = left;
    while (third != nullptr) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    while (first != nullptr) {
        if (head->val != first->val) return false;
        head = head->next;
        first = first->next;
    }
    return true;
}