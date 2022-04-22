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
    int i;
    TreeNode* helper(vector<int> & v, int bound)
    {
        if(i>=v.size() || v[i] > bound)return NULL;
        TreeNode * r = new TreeNode(v[i]);
        i++;
        r->left = helper(v,r->val);
        r->right = helper(v,bound);
        return r;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        i=0;
        return helper(preorder,INT_MAX);
    }
};