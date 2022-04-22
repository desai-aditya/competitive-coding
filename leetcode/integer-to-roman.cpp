class Solution {
public:
    string intToRoman(int num) {
        string s="";
        if(num>=1000)
        {
            for(int i  = 0 ;i < num/1000; i++)s+="M";
            num=num%1000;
        }
        if(num>=100)
        {
            if(num/100==4)
            {
                s+="CD";
            }
            else if(num/100==9)
            {
                s+="CM";
            }
            else 
            {
                if(num/100>=5)
                {
                    num-=500;
                    s+="D";                    
                }
                
                for(int i = 0 ; i <num/100; i++)s+="C";
            }
            num=num%100;

        }
        if(num>=10)
        {
            if(num/10==4)
            {
                s+="XL";
            }
            else if(num/10==9)
            {
                s+="XC";
            }
            else 
            {
                if(num/10>=5)
                {
                    num-=50;
                    s+="L";                    
                }
                
                for(int i = 0 ; i <num/10; i++)s+="X";
            }
            num=num%10;

        }
        if(num)
        {
            if(num==4)
            {
                s+="IV";
            }
            else if(num==9)
            {
                s+="IX";
            }
            else 
            {
                if(num>=5)
                {
                    num-=5;
                    s+="V";                    
                }
                
                for(int i = 0 ; i <num; i++)s+="I";
            }
            num=num%1;

        }
        return s;
    }
};