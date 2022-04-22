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
    int helper(TreeNode * r)
        {
        
        if(r==NULL) return 0;
        
        int a = helper(r->left);
        if(0==a)r->left=NULL;
        int b = helper(r->right);
        if(0==b)r->right=NULL;
        return a|b|r->val;
        
        }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!helper(root))return NULL;
        return root;
    }
};