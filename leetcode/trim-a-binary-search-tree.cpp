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
    
    TreeNode* solve(TreeNode * root, int low, int high)
    {
        if(root->val > high)
        {
            if(root->left!=NULL)
                return solve(root->left,low,high);
            else
                return NULL;
            
        }
        else if(root->val < low)
        {
            if(root->right!=NULL)
                return solve(root->right,low,high);
            else
                return NULL;
        }
        else
        {
            if(root->right!=NULL)
                root->right = solve(root->right,low,high);
            else
                root->right =  NULL;
            if(root->left!=NULL)
                root->left = solve(root->left,low,high);
            else
                root->left = NULL;
            return root;
        }
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode * ans;
        if(root!=NULL)
            ans=solve(root,low,high);
        return ans;
    }
};