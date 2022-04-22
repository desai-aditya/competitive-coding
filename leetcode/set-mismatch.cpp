class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v(2,0);
        for( auto el: nums)m[el]++;
        for ( int i=1; i<=nums.size(); i++)
            {
                if(m[i]==2)v[0]=i;
                else if(m[i]==0)v[1]=i;
            }
        return v;
    }
};