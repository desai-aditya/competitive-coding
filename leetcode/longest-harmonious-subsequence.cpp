class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i < nums.size(); i++)
            {
            
            m[nums[i]]++;
            
            }
        if(m.size()==1)return 0;
        int ans = INT_MIN;
        for(auto itr=m.begin(); itr!=m.end();itr++)
            {
            
            if(m.find(itr->first-1)!=m.end())
                ans=max(ans,itr->second + m[itr->first-1]);
            
            if(m.find(itr->first+1)!=m.end())
                 ans=max(ans,itr->second + m[itr->first+1]);
            
            }
               return ans==INT_MIN?0:ans;
    }
};