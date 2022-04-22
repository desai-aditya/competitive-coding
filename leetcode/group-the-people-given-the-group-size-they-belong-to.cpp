class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector< vector<int> > arr(n+1);
        for(int i = 0 ; i < n; i++)
        {
            arr[groupSizes[i]].push_back(i);
        }
        vector< vector<int> > ans;
        for(int i = 1 ; i <= n; i++)
        {
            vector<int> temp;
            if(arr[i].size()>0)
            for(auto itr = arr[i].begin(); itr!=arr[i].end(); itr++)
            {
                temp.push_back(*itr);
                if(temp.size()==i)
                {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
        
    }
};