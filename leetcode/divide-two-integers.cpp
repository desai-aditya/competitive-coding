class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        bool isneg = false;
        if(dividend<0 || divisor < 0 )isneg=true;
        if(dividend<0 && divisor < 0 )isneg=false;
        if(dividend == INT_MIN && divisor<0)
        {
            dividend = 2147483647;
        }
        if(dividend!=INT_MIN)
            dividend = abs(dividend);
        if(divisor!=INT_MIN)
            divisor = abs(divisor);
        //cout<<dividend<<endl;


        if(divisor==INT_MIN)return 0;
        if(dividend!=INT_MIN && divisor!=INT_MIN && dividend<divisor)return 0;
        
        
        int q = 0;

        if(divisor==1)
        {
             q=dividend;
             //cout<<q<<endl;
        }
        else
        {
            if(dividend!=INT_MIN)
            {
                while(dividend>0)
                {
                    dividend-=divisor;
                    q++;
                }
                if(dividend < 0)q--;
            }
            else
            {
                while(dividend<0)
                {
                    dividend+=divisor;
                    q++;
                }
                if(dividend > 0)q--;
            }

        }
        
        if(isneg && q!=INT_MIN)q=-q;
        if(q<-2147483648 || q>2147483647)q=2147483647;
        return q;
    }
};