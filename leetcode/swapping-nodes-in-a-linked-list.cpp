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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp = head;
        int n=0;
        while(temp)
            {
                arr.push_back(temp->val);
                temp=temp->next;n++;
            }
         
        int t= arr[k-1];
        arr[k-1]= arr[n-k];
        arr[n-k]=t;
        temp=head;
        int i=0;
        while(temp)
            {
                 temp->val=arr[i];
                 temp=temp->next; i++;
            }
        return head;
        

        
        
    }
};