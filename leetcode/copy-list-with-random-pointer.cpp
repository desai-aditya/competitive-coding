/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        unordered_map<Node* , Node *> m;
        Node * temp = head;
        Node * newhead = new Node(head->val);
        Node * newtemp = newhead;
        m[temp]=newtemp;
        temp = temp->next;
        while(temp!=NULL)
        {
            Node * newnode = new Node(temp->val);
            newtemp->next = newnode;
            m[temp]=newnode;
            temp=temp->next;
            newtemp=newtemp->next;
        }
        
        temp = head;
        newtemp = newhead;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
                newtemp->random = m[temp->random];
            temp=temp->next;
            newtemp=newtemp->next;
        }
        
        return newhead;
        
    }
};