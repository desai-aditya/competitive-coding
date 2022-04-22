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
    
    void helper(TreeNode * root,vector<vector<int> >& levels, int depth)
    {
        if(root==NULL)return;
        
        if(levels.size()==depth)
            levels.push_back(vector<int>());
        levels[depth].push_back(root->val);
        
        helper(root->left,levels,depth+1);
        helper(root->right,levels,depth+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int> > levels;
        
        helper(root,levels,0);
        
        vector<double> ans;
        for(int i  =0 ; i < levels.size() ;  i++)
        {
            double t =0.0;
            for(int j = 0  ; j < levels[i].size(); j++)
            {
                t+=levels[i][j];
            }
            ans.push_back(t/levels[i].size());
        }
        return ans;
        
    }
};