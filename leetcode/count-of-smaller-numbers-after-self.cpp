#define vlli vector<long long int>
#define vi vector<int>
#define vlln vector<node>
#define lli long long int
#define lc 2*x
#define rc 2*x+1


struct node{
    node * left,*right;
    lli val;
};

class SegmentTree{
private:            
    //vlli _st,_arr;
    node * _root;
    lli _n,_min,_max;
    
    
    
    lli _combine(lli a, lli b)
    {
        return a+b;
    }
    
    // void _build(int x, int l ,int r)
    // {
    //     if(l==r)
    //     {
    //         _st[x] = _arr[l-1];
    //         return;
    //     }
    //     int mid = (l+r)>>1;
    //     _build(lc,l,mid);
    //     _build(rc,mid+1,r);
    //     _st[x] = _combine(_st[lc],_st[rc]);
    // }
    
    node * _getnode()
    {
        node* newnode = new node();
        newnode->val = 0;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    
    lli _getsum(int lqueryidx, int rqueryidx, node * root, int l , int r)
    {
        if(root==NULL)return 0;
        if(rqueryidx<l || lqueryidx>r)return 0;
        if(lqueryidx<=l && r<=rqueryidx)return root->val;        
        int mid = (l+r)>>1;
        return _combine( _getsum(lqueryidx,rqueryidx,root->left,l,mid), _getsum(lqueryidx,rqueryidx,root->right,mid+1,r));
    }
    
    void _update(int idx, int val,node * root, int l ,int r)
    {
        if(idx<l || idx>r)return;
        if(l==r)
        {
            root->val+=val;
            return;
        }
        int mid = (l+r)>>1;
        
        if(idx<=mid)
        {
            if(root->left==NULL)
                root->left = _getnode();
            
            _update(idx,val,root->left,l,mid);
        }
        else
        {
            if(root->right==NULL)
                root->right = _getnode();
            _update(idx,val,root->right,mid+1,r);
        }
        
        if(root->left==NULL && root->right!=NULL)
        {
            root->val = root->right->val;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            root->val = root->left->val;
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            root->val = _combine( root->left->val,root->right->val);
        }
        else
        {
            root->val = 0;
        }
        
    }
    
public:
    SegmentTree(int min, int max)
    {
        _min = min;
        _max = max;
        //_arr=arr;
        // lli nx2pow = 1;
        // while(nx2pow<max-min)nx2pow*=2;
        // _n=nx2pow;
        
        //_arr = vlli(_n,0);
        //_st = vlli(2*_n,0);
        _root = _getnode();
        _root->val = 0;
        
        
       // _build(root,min,max);        
    }
    
    lli getsum(int l,int r)
    {
        return _getsum(l,r,_root,_min,_max);
    }
    
    void update(int idx, int val)
    {
        _update(idx,val,_root,_min,_max);
    }
    
    
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        
        vi ans(nums.size(),0);
        lli maxel = *max_element(nums.begin(),nums.end());
        lli minel = *min_element(nums.begin(),nums.end());
        SegmentTree st(minel,maxel);
        
        for(int i = nums.size()-1; i>=0 ;i-- )
        {
            
            ans[i]=st.getsum(minel,nums[i]-1);
            st.update(nums[i],1);
        }
        return ans;
        
    }
};