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
    vector<int> inorderTraversal(TreeNode* root) {
        stack< pair<bool,TreeNode*> > s;
        vector<int> v;
        s.push({0,root});
        
        while(!s.empty())
        {
            auto f = s.top();s.pop();
            if(!f.first)
            {
                if(f.second!=NULL)
                {
                    if(f.second->right!=NULL)
                        s.push({0,f.second->right});
                    
                    s.push({1,f.second});
                    
                    if(f.second->left!=NULL)
                        s.push({0,f.second->left});
                }                                
            }
            else
            {
                v.push_back(f.second->val);
            }
        }
        return v;
    }
};