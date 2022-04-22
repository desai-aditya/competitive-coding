class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<=2)return 0;
        A.push_back(INT_MAX);
        int ans = 0;
        long long int diff = A[1]-A[0];
        int len = 2;
        int i = 2;
        
        
        for(  ; i < A.size()  ; i++)
        {      
            while(i < A.size()&& diff == ((long)A[i]-A[i-1]))
            {
                i++;
                len++;
            } 
            //if( diff != (A[i]-A[i-1]) )
           // {
                if(len!=2)
                {
                    //cout<<len<<endl;
                    //len--;
                    ans += (len*(len+1)/2)-len-(len-1);
                }
                    
                //cout<<i<<endl;
                len = 2;
                diff =(long) A[i] - A[i-1];                
            //}
           
                       
        }
        
        return ans;
    }
};