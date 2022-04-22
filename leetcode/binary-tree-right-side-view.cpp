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
    
    
    void _helper(TreeNode* root, int level, vector<int>&a)
        {
            if(root==NULL)return;
        
            

            _helper(root->left,level+1,a);
             a[level]=root->val;
            _helper(root->right,level+1,a);
        
        }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> a(500,INT_MIN);
        _helper(root,0,a);
        int cnt=-1;
        for(int i=0; i < 500; i++)
            if(a[i]==INT_MIN)
                {
                     cnt=i;
                     break;
                }
        a.erase(a.begin()+cnt,a.end());
        return a;
        
    }
};