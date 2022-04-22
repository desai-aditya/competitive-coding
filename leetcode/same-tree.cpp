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
    
    bool flag;
    void _helper(TreeNode*p, TreeNode*q)
        {
            if(p!=NULL && q!=NULL){
                
                if(p->val != q-> val)
                    flag=false;
                
                _helper(p->left,q->left);

            _helper(p->right,q->right);
                }
            if(p!=NULL&&q==NULL)
                {
                flag=false;return;
                }
            if(p==NULL&&q!=NULL)
                {
                flag=false;return;
                }
        
            
        
        }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        flag=true;
        _helper(p,q);
        return flag;
        
    }
};