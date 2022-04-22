class Solution {
public:
        vector< pair<int,int> > s;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ngel(nums2.size());
        unordered_map<int,int> m={};
        for(int i = 0; i < nums2.size(); i++)
        {
            if(!s.empty())
            {
                while(!s.empty() && s.back().first<nums2[i])
                {
                    auto t=s.back();
                    ngel[t.second]=nums2[i];
                    s.pop_back();
                }
            }
            s.push_back( {nums2[i],i} );
            m[nums2[i]]=i;
        }
        while(!s.empty())
        {
            auto t = s.back();
            ngel[t.second]=-1;
            s.pop_back();
        }
        vector<int> ans(nums1.size());
        for(int i = 0 ; i < nums1.size(); i++)
        {
            ans[i]=ngel[m[nums1[i]]];
        }
        return ans;
        
    }
};