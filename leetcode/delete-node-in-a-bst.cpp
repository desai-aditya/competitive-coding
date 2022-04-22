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
/*
            if(root->left == NULL && root->right == NULL)return NULL;
            
            if(root->left !=NULL)
            {
                if(root->left->right==NULL){
                    root->left->right = root->right;
                    return root->left;
                }
                else
                {
                    TreeNode* temp = root->left->right;
                    root->left->right = root->right;
                    temp->left
                }
            }
            */
class Solution {
public:
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;
        
        if(key==root->val)
        {
            
            if(root->right!=NULL)
            {
                /*
                if(root->left->right==NULL)
                {
                    root->left->right = root->right;
                    root = root->left;
                }
                else
                {
                    TreeNode* par = root->left;
                    TreeNode* cur = root->left->right;
                    
                    while(cur->right!=NULL)
                    {
                        par = cur;
                        cur = cur->right;
                    }
                    par->right = cur->left;
                    cur->right = root->right;
                    cur->left = root->left;
                    root = cur;
                }*/
                
                 if(root->right->left==NULL)
                {
                    root->right->left = root->left;
                    root = root->right;
                }
                else
                {
                    TreeNode* par = root->right;
                    TreeNode* cur = root->right->left;
                      
                    while(cur->left!=NULL)
                    {
                        par = cur;
                        cur = cur->left;
                    }
                    par->left = cur->right;
                    cur->left = root->left;
                    cur->right = root->right;
                    root = cur;
                }
                 

            }
            else if(root->left!=NULL)
            {
                root=root->left;                                                          
            }
            else return NULL;
            
            return root;
        }
        else if(key<root->val)root->left=deleteNode(root->left,key);
        else if(key>root->val)root->right=deleteNode(root->right,key);
        return root;
    }
};