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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        
        // Traverse the linked list from head to tail
        while (head != nullptr) {
            // Left shift result by 1 bit and add current node's value
            result = (result << 1) | head->val;
            
            // Move to next node
            head = head->next;
        }
        
        return result;
    }
};