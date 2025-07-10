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
    ListNode* middleNode(ListNode* head) {
      vector<int> arr;
        int count=0;
        ListNode* temp=head;
     while (temp != nullptr) {
            arr.push_back(temp->val);  
            temp = temp->next;
            count++;
        }
      int d=count/2;
     temp = head;
        for (int i = 0; i < d; i++) {
            temp = temp->next;
        }
        return temp; 
    }
};