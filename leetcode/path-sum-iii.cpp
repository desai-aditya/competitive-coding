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
    unordered_map<int,int> m;
    int c;
    void helper(TreeNode* root, int t, int s)
    {
        if(!root)return;
        s+=root->val;
        if(s==t)c++;
        if(m.find(s-t)!=m.end())
            c+=m[s-t];
        m[s]++;
        helper(root->left,t,s);
        helper(root->right,t,s);
        m[s]--;
         
    }
    int pathSum(TreeNode* root, int targetSum) {
        m={};c=0;
     helper(root,targetSum,0);
    
    return c;}
};