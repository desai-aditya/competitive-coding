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
    struct node{
        TreeNode* trnode;
        int level;
        
       };
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int arr[1000]={};
        queue<node> q;
        q.push({root,1});
        int maxlvl=-1;
        while(!q.empty())
        {
            node cur = q.front();
            q.pop();
                    maxlvl=max(maxlvl,cur.level); arr[cur.level]+=cur.trnode->val;
            if(cur.trnode!=NULL)
            {
                if(cur.trnode->left!=NULL)
                q.push({cur.trnode->left,cur.level+1});
                if(cur.trnode->right!=NULL)
                q.push({cur.trnode->right,cur.level+1});
           
            }

        }
        int maxel= INT_MIN;
        int anslvl = -1;
        
        for (int i=maxlvl; i>=1; i--)
            {
                if(maxel<=arr[i])
                    {
                        maxel=arr[i];
                        anslvl = i;
                    
                    }
            
            }
        return anslvl;
    }
};