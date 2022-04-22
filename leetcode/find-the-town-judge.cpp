class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector< vector<int> > trustg(N,vector<int>(N,0));
        for(int i = 0 ;i  < trust.size(); i++)
        {
            trustg[trust[i][0]-1][trust[i][1]-1]=1;
        }
        
        int judge=-1;
        for(int i = 0 ;i < N; i++)
        {
            int found=1;
            for(int j = 0 ; j < N; j++)
            {
                if(trustg[i][j]){found=0;break;}
            }
            
            if(found==0)continue;
            
            if(judge!=-1)return -1;
            
            int flag=0;
            for(int k = 0 ; k < N; k++)
            {
                if(k!=i)
                    if(!trustg[k][i]){flag=1;break;}
            }
            if(flag==0)judge=i;
            
        }
        return judge==-1?-1:judge+1;
    }
};