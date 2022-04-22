/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node * flatten(Node * head){
        if(!head)return NULL;
        Node * cur = head;
    while(cur)
    {
        if(cur->child)
        {
            Node * x = cur->child;
            while(x->next)x=x->next;
            x->next=cur->next;
            if(cur->next)cur->next->prev=x;
            cur->next=cur->child;
            cur->child->prev=cur;
            cur->child=nullptr;
        }
        cur=cur->next;
    }
    return head;
    }
    };