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
    int ans=INT_MIN;
    
    int _maxPathSum(TreeNode* root)
    {
        if(root==NULL)return 0;
        
        int l = _maxPathSum(root->left)+root->val;
        int r = _maxPathSum(root->right)+root->val;
        
        int onlyOneNode  = max(max(l,r),root->val);
        
        ans = max(ans, max(onlyOneNode,l+r-root->val));
        return onlyOneNode;
    }
    
    int maxPathSum(TreeNode* root) {
    
        _maxPathSum(root);
        return ans;
        
        
    }
};