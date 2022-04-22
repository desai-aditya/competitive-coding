class Solution {
    public int countBinarySubstrings(String s) {
        int onesptr = 0;int onescount = 0;int zerosptr = 0;int zeroscount = 0;int ptr = 0;
        int ans = 0;
        if(s.charAt(0)=='0')zeroscount++;
        else onescount++;
        
        for(int i = 1 ; i < s.length(); i++)
        {
            if(s.charAt(i)=='1')
            {
                if(s.charAt(i-1)=='0')onescount=0;
                onescount++;
                if(zeroscount>0)
                {
                    ans++;
                    zeroscount--;
                }
                
            }
            else
            {
                if(s.charAt(i-1)=='1')zeroscount=0;
                zeroscount++;
                if(onescount>0)
                {
                    ans++;
                    onescount--;
                }
                
            }
        }
        
//         while(onesptr < s.length() && zerosptr < s.length())
//         {
//             if(ptr==1)
//             {
                
//                 while(onesptr<s.length() && s.charAt(onesptr)=='1')
//                 {
//                     onesptr++;
//                     onescount++;
//                 }
//                 ptr=0;
//                 zerosptr=onesptr;
//                 ans+= Math.min(onescount,zeroscount);
//                 zeroscount=0;
//             }
//             else
//             {
                
//                 while(zerosptr<s.length() && s.charAt(zerosptr)=='0')
//                 {
//                     zerosptr++;
//                     zeroscount++;
//                 }
//                 ptr=1;
//                 onesptr=zerosptr;
//                 ans+= Math.min(onescount,zeroscount);
//                 onescount=0;

//             }
//         }
        //ans+= Math.min(onescount,zeroscount);
        return ans;
    }
}