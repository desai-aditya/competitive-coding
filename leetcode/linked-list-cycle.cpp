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
    bool hasCycle(ListNode *head) {
        
        if(head==NULL || head->next == NULL || head->next->next == NULL)return false;
        
        ListNode * fastptr = head->next->next;
        ListNode * slowptr = head->next;
        
        
        while(fastptr!=NULL && slowptr != NULL)
        {
            if(fastptr->next!=NULL)fastptr=fastptr->next;
            else break;
            if(fastptr->val==slowptr->val)return true;
            if(fastptr->next!=NULL)fastptr=fastptr->next;

            if(slowptr->next!=NULL)slowptr=slowptr->next;

            if(fastptr->val==slowptr->val)return true;
        }
        return false;
    }
};