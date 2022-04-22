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
    int h;
    void height(TreeNode*root,int d)
        {
        if(!root)return;
        h=max(h,d);
        height(root->left,d+1);
        height(root->right,d+1);
        
        }
    
    void dfs(TreeNode* root,int d)
        {
             if(!root)return;
             if(d==h){ans+=root->val;}
             dfs(root->left,d+1);
        dfs(root->right,d+1);
        
        }
    int deepestLeavesSum(TreeNode* root) {
        ans=0;
        height(root,0);
        dfs(root,0);
        return ans;
    }
};