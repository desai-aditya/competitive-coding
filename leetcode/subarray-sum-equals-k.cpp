class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans=0,cursum=0;
        map<int,int> m{};
        for(int i = 0 ; i < nums.size();i++)
        {
            cursum+=nums[i];
            if(cursum==k)ans++;
            
            if(m.find(cursum-k) != m.end())
                ans+= (m[cursum-k]);
            
            m[cursum]++;
            
        }
        return ans;
    }
};