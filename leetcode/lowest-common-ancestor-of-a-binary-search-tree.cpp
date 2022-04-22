/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    
public:
    vector<TreeNode*> parents;
    void getparents(TreeNode* root, TreeNode* x)
    {
        if(root==NULL)return ;
        parents.push_back(root);
        if(root->val==x->val)return;
        else if(root->val<x->val)getparents(root->right,x);
        else getparents(root->left,x);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parents = {};
        getparents(root,p);
        auto pparents = parents;
        parents={};
        getparents(root,q);
        auto qparents = parents;
        int i;
        for(i = 0 ; i < pparents.size() && i<qparents.size(); i++)
        {
            if(pparents[i]->val!=qparents[i]->val)break;
        }
        i--;
        if(i<0)return NULL;
        return pparents[i];
    }
};