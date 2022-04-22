class Solution {
public:
    
    int brokenCalc(int X, int Y) {
        int ans = 0;
        if(Y==X)return 0;
        while(true)
        {
            if(X>=Y)
                {
                    ans+=X-Y;
                    break;
                }
            
            if(Y%2==0)
            {
                
                Y/=2;
                ans+=1;
            }    
            else
            {
                Y+=1;
                ans+=1;
            }
        }
        return ans;
        
    }
};