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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static ListNode h;
    public int getLength(ListNode head)
    {
        // if(head==null)return 0;
        int counter=0;
        while(head!=null)
        {
            counter++;
            head=head.next;
        }
        return counter;
    }
    public TreeNode _sortedListToBST(int start, int end)
    {
        if(start>end)return null;
        int mid = (start+end)/2;
        
        TreeNode left = _sortedListToBST(start,mid-1);
        TreeNode root = new TreeNode(h.val);
        h = h.next;
        TreeNode right  = _sortedListToBST(mid+1,end);
        root.left=left;
        root.right=right;
        return root;

    }
    public TreeNode sortedListToBST(ListNode head) {
        if(head==null)return null;
        h=head;
        int n = getLength(head);
        return _sortedListToBST(1,n);
    }
}