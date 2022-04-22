class Solution {
public:
    int ans=0;
    void helper(int x, int n)
        {
            if(x<=n)ans++;
            if(x>n)return;
            if(x%2==0)
                {
                    helper(2*x,n);
                    helper(2*x+1,n);
                
                }
        else{
                 helper(2*x,n);
            }
        }
    
    int findIntegers(int n) {
       
                        ios_base::sync_with_stdio(NULL);
       int f[32]= {};
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30,sum=0,prev=0;
        while(i>=0)
            {
            if((n&(1<<i)) !=0){
                sum+=f[i];
                if(prev==1){sum--;
                            break;}
                prev=1;
                }
            else prev=0;
            i--;
            
            
            }
        
    

        return sum+1;
        
    }
};