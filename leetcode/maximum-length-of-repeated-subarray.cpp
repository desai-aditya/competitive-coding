class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int> > v = vector<vector<int> >(n,vector<int>(m,-1));
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m   ; j ++)
            {
                if(v[i][j]==-1)
                {
                    int k=0;
                    for(k = 0; i+k<n && j+k<m && nums1[i+k]==nums2[j+k] ; k++);
                    v[i][j]=k;
                    int t = 0;
                    while(k)
                    {
                        v[i+t][j+t]=k;
                        t++;
                        k--;
                    }
                }
                ans = max(ans,v[i][j]);
            }
        }
        return ans;
    }
};