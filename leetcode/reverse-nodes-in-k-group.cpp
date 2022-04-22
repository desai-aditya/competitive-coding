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
    int length(ListNode * h)
    {
        int c  =0 ;
        while(h!=NULL)
        {
            c++;
            h=h->next;
        }
        return c;
    }
    void  print(ListNode * h)
    {
        while(h!=NULL)
        {
            cout<<h->val<<" ";
            h=h->next;
        }
        cout<<endl;
    }
    // 1 2 3 4 5
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        int l = length(head);
        ListNode * mainptr = head, *prevmain = NULL;
        
        for(int i = 0 ;  i < l/k ; i++)
        {
            ListNode * cur = mainptr->next;
            ListNode * prev =mainptr;
            ListNode * next ;
            for(int j = 0 ; j < k-1 ; j ++)
            {
                //print(head);

                //cur=cur->next;
                next = cur->next;
                cur->next = prev;
                
                if(j==k-2)break;
                else { 
                    prev = cur;
                    cur=next;
                    continue;
                }

            }
            
            if(i==0)head = cur;
            else prevmain->next = cur;
            prevmain = mainptr;
            mainptr->next=next;
            mainptr = next;
            //prevmain->next = cur;
        }
        return head;
    }
};