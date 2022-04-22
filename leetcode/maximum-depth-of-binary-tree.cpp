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
private:
    int _max_depth{};
    void _find_max_depth(TreeNode * root, int depth)
    {
        
        if(root==NULL)
        {
            _max_depth=max(_max_depth,depth);
        }
        else
        {
            depth+=1;
        
            _find_max_depth(root->left,depth);
            _find_max_depth(root->right,depth);
        }
    }
public:
    
    int maxDepth(TreeNode* root) {
        _max_depth=-1;
        
        _find_max_depth(root,0);
        
        return _max_depth;
    }
};