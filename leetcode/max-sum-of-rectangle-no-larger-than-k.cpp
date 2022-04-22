class Solution {
public:
    int result  = INT_MIN;
    
    void updateResult(vector<int> & v, int k)
    {
        set<int> s;
        int runsum = 0 ; 
        s.insert(0);
        for(int i = 0 ; i  < v.size() ; i ++)
        {
            runsum += v[i];
            auto it = s.lower_bound(runsum-k);
            
            if(it!=s.end())
            {
                result = max(result,runsum-*it);
            }
            
            
            s.insert(runsum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int x) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v = vector<int>(m);
        for(int i =  0 ;i <  n ; i ++)
        {
            fill(v.begin(),v.end(),0);
            for(int row = i; row < n ; row++)
            {
                
                for(int col = 0 ; col < m ; col++)
                {
                    v[col]+=matrix[row][col];
                    
                }
                updateResult(v,x);
                if(result==x)return x;
            }
        }
        return result;
        
        
    }
};