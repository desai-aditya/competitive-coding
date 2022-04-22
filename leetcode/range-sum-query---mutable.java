class SegmentTree{
    private int _n;
    private ArrayList<Integer> _st;
    
    int _combine(int a, int b)
    {
        return a+b;    
    }
    
    private void build(int[] nums,int x, int l, int r)
    {
        /*
        System.out.println(x);
        System.out.println(l);
        System.out.println(r);
        */
        if(l==r)
        {
            if(l<=nums.length)
                _st.set(x,nums[l-1]);
            return;
        }
        int mid = (l+r)/2;
        build(nums,2*x,l,mid);
        build(nums,2*x+1,mid+1,r);
        _st.set(x, _combine(_st.get(2*x),_st.get(2*x+1)) );
    }
    
    public SegmentTree(int[] nums)
    {
        _n=1;
        while( _n < nums.length ) _n=_n*2;
        //_st = Arrays.asList(nums);
        _st = new ArrayList<Integer>(2*_n+1);
        /*
        for(int i = 0 ; i < nums.length; i++)
        {
            _st.add(nums[i]);
        }
        */
        
        for(int i = 0  ; i <= 2* _n+1; i++ )
        {
            _st.add(0);
        }
        
        build(nums,1,1,_n);
    }
    
    private void update(int index, int val, int x, int l, int r)
    {
        if(index<l || index>r) return;
        if(l == r)
        {
            _st.set(x,val);
            return;
        }
        int mid = (l+r)/2;
        update(index,val,2*x,l,mid);
        update(index,val,2*x+1,mid+1,r);        
        _st.set(x, _combine(_st.get(2*x),_st.get(2*x+1)) );
    }
    
    private int sum(int leftinterval, int rightinterval, int x, int l, int r)
    {
        if(l>rightinterval || leftinterval>r)return 0;
        
        if(leftinterval <= l && r <= rightinterval)
        {
            return _st.get(x);
        }
        int mid = (l+r)/2;
        return _combine( sum(leftinterval, rightinterval, 2*x, l, mid), sum(leftinterval, rightinterval, 2*x+1,  mid+1,r) );
        
        
    }
    
    public void update(int index, int val)
    {
        update(index,val,1,1,_n);
    }
    
    
    public int sum(int l, int r)
    {
        return sum(l,r,1,1,_n);
    }
}

class NumArray {
    SegmentTree st;
    public NumArray(int[] nums) {
        st = new SegmentTree(nums);
    }
    
    public void update(int index, int val) {
        st.update(index+1,val);
    }
    
    public int sumRange(int left, int right) {
        return st.sum(left+1,right+1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */