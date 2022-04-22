class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int> > v = vector<vector<int> >(5,vector<int>(n+1));
        int mod = 1000000007;
            for(int j = 1; j <= n; j ++)
            {
                if(j==1)v[0][j]=v[1][j]=v[2][j]=v[3][j]=v[4][j]=1;
                else
                {
                    v[0][j] =(((v[0][j] +  v[1][j-1])%mod+v[2][j-1])%mod+v[4][j-1])%mod;
                    v[1][j] =((v[1][j] +  v[0][j-1])%mod+v[2][j-1])%mod;
                    v[2][j] =((v[2][j] +  v[1][j-1])%mod+v[3][j-1])%mod;
                    v[3][j] =(v[3][j] +  v[2][j-1])%mod;
                    v[4][j] =((v[4][j] +  v[2][j-1])%mod+v[3][j-1])%mod;
                }
            }
        
        return ((((v[0][n]+v[1][n])%mod+v[2][n])%mod+v[3][n])%mod+v[4][n])%mod;
        
    }
};