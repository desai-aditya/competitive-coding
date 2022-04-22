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
    ListNode* partition(ListNode* head, int x) {
        vector<int> arr;
        ListNode * newnode = new ListNode(1000,head);
        ListNode* t = head, *tk = newnode, *prev = newnode;
        while(t!=NULL)
        {
            if(t->val < x){
                t=t->next;
                prev=prev->next;
                tk=tk->next;
            }
            else break;
        }
        while(t!=NULL)
        {
            if(t->val < x)
            {
                ListNode* temp = tk->next;
                tk->next = t;
                prev->next = t->next;
                t->next = temp;
                t=prev->next;
                tk=tk->next;
            }
            else
            {
                t=t->next;
                prev=prev->next;
            }
            
        }
        return newnode->next;
        
    }
};