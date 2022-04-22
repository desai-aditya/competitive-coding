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
    bool _isValidSequence(TreeNode* root, vector<int>& arr, int index) {
            
        if(root==NULL || index>=arr.size() || root->val != arr[index])return 0;
        
        if(root->left==NULL && root->right==NULL && index == (arr.size()-1) )return 1;
        
        
        cout<<root->val<<endl;
        
        return max(_isValidSequence(root->left,arr,index+1),_isValidSequence(root->right,arr,index+1));
        
        
        
        
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        
        return _isValidSequence(root,arr,0);
    }
};