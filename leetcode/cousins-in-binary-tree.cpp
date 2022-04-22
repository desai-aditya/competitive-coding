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
    TreeNode* p;
    int helper(TreeNode* r, int x)
    {
        if(!r)return 0;
        if(r->val==x)return 1;
        int d=0;
        if(r->left!=NULL)
        {
            d=helper(r->left,x);
            if(r->left->val==x)p=r;
        }
        if(d!=0)return d+1;
        if(r->right!=NULL)
        {
            d=helper(r->right,x);
            if(r->right->val==x)p=r; 
        }
        if(d!=0)return d+1;
        return 0;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d1 = helper(root,x);
        TreeNode* p1 = p;
        int d2 = helper(root,y);
        TreeNode* p2=p;
        return p1!=p2&&d1==d2;
    }
};