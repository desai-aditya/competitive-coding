/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    int getlen(ListNode * node)
    {
        int i =0;
        while(node!=NULL)
        {
            i++;
            node=node->next;
        }
        return i;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getlen(headA);
        int lenB = getlen(headB);
        
        ListNode * ptr1 = headA;
        ListNode * ptr2 = headB;
        
        if(lenA<lenB)
        {
            swap(ptr1,ptr2);
            swap(lenA,lenB);   
        }
        
        for(int i = 0; i < lenA-lenB; i++)
        {
            ptr1 = ptr1->next;
        }
        
        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(ptr1==ptr2)return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;            
        }
        return NULL;
        
        
    }
};