class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long ans= left;
        for(long long i=left;i<=right;i++)
            {
                ans= ans&i;
            if(ans==0)return 0;
            }
        return ans;
        
    }
};