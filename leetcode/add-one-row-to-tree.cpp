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
    
    void helper(TreeNode * root, int v, int d, int curd)
    {
        if(root==NULL)return;
        if(curd==d-1)
        {            
            TreeNode* newnode = new TreeNode(v);
            newnode->left=root->left;
            root->left = newnode;
            newnode = new TreeNode(v);
            newnode->right=root->right;
            root->right=newnode;

        return;
        }
        
        helper(root->left,v,d,curd+1);
        helper(root->right,v,d,curd+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode* newnode = new TreeNode(v);
            newnode->left=root;
            return newnode;
        }
        
        helper(root,v,d,1);
        return root;
    }
};