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
    int dfs(TreeNode * root)
    {
        if(root==NULL)return 0;
        int val = dfs(root->left) + dfs(root->right);
        if(val==0)return 3;
        if(val<3)return 0;
        ans++;
        return 1;
    }    
    
    int minCameraCover(TreeNode* root) {
        ans = 0;
        return dfs(root)>=3? ans+1:ans;
    }
};