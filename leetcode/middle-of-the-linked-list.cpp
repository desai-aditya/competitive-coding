/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * fast{head},*slow{head};
        
        while(fast != NULL&& fast->next != NULL)
        {
            fast=fast->next;
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
        
    }
};