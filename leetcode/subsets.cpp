class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        for(int i = 0 ; i < pow(2,nums.size()); i++ )
        {
            vector<int> temp;
            int j = i;
            int counter = 0;
            while(j)
            {
                if(j%2)temp.push_back(nums[counter]);
                j/=2;
                counter++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};