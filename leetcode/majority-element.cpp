class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int, int> m{};
        int ans=nums[0];
        m[nums[0]]++;
        for(int i = 1 ; i < nums.size(); i++)
        {
            if(ans==nums[i])
            {
                m[nums[i]]++;
            }
            else
            {
                if(m[ans]==0)
                {
                    m[nums[i]]++;
                    ans=nums[i];
                }
                else
                {
                    m[ans]--;
                }
            }
        }
        return ans;
        
    }
};