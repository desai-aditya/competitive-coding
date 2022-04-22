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
    public TreeNode flattenHelper(TreeNode root)
    {
        if(root==null)return null;
        
        TreeNode left = flattenHelper(root.left);
        TreeNode right = flattenHelper(root.right);    

        root.left=null;
        TreeNode temp = root.right;
        TreeNode itr = left;
        while(itr!=null&&itr.right!=null)itr=itr.right;
        
        if(itr!=null)
            itr.right=right;
        else
            left=right;
        
        root.right=left;
        return root;
    }
    public void flatten(TreeNode root) {
        root = flattenHelper(root);
        
    }
}