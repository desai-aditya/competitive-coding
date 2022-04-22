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
    HashMap<Integer, ArrayList<Integer> > m;
    public void dfs(TreeNode root, int level)
    {
        if(root==null)return;
        dfs(root.left,level+1);
        if(m.get(level)==null)
        {
            ArrayList<Integer> arr = new ArrayList<Integer>();
            m.put(level,arr);
        }
        ArrayList<Integer> arr = m.get(level);
        arr.add(root.val);
        dfs(root.right,level+1);
        
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        m=new HashMap<Integer, ArrayList<Integer> >();
        dfs(root,0);
        ArrayList<List<Integer> > ans =new  ArrayList<List<Integer> >();
        for(int i = 0 ; i < 1000; i ++)
        {
            if(m.containsKey(i))
            {
                ans.add(m.get(i));
            }
            else
                break;
        }
        return ans;
    }
}