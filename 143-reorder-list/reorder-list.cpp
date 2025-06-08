/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        return;

    // Find the middle of the list
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (p2->next != nullptr && p2->next->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // Reverse the half after middle
    ListNode* preMiddle = p1;
    ListNode* preCurrent = p1->next;
    while (preCurrent->next != nullptr) {
        ListNode* current = preCurrent->next;
        preCurrent->next = current->next;
        current->next = preMiddle->next;
        preMiddle->next = current;
    }

    // Start reordering
    p1 = head;
    p2 = preMiddle->next;
    while (p1 != preMiddle) {
        preMiddle->next = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = preMiddle->next;
        
    }
}   
};