/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummynode = new ListNode(-1,head);
        ListNode temp = head;
        if(n==1)
        {                   
            if(temp.next==null)return null;
            while(temp.next.next != null)
            {
                temp=temp.next;
            }
            temp.next=null;
        }
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                temp=temp.next;
            }
            
            ListNode slownode = head;
            
           while(temp!=null)
           { 
             temp=temp.next;
               slownode=slownode.next;
           }
            slownode.val = slownode.next.val;
            slownode.next = slownode.next.next;
        }
        return dummynode.next;
    }
}