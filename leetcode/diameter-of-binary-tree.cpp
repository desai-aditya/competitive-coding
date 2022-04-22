/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int helper(TreeNode* root)
        {
            if(!root )return 0;
            int l= helper(root->left);
            int r= helper(root->right);
            ans = max(ans,1+l+r);
            return 1+max(l,r);
        }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        helper(root);
        return ans-1;
    }
};