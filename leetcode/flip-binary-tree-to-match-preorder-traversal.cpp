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
    vector<int> ans;
    int index;
        void helper(TreeNode* root, vector<int>& v)
        {
            if(!root || (ans.size()>0 && ans[0]==-1))return ;
            if(root->val != v[index++])ans = {-1};
            else if (root->left && root->left->val != v[index])
            {
                ans.push_back(root->val);
                helper(root->right,v);
                helper(root->left,v);                
            }
            else
            {
                helper(root->left,v);                
                helper(root->right,v);
            }
        }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {   
        index=0;
        helper(root,voyage);
        return ans;
    }
};