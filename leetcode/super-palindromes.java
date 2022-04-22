class Solution {
    public Boolean isPalindrome(String s)
    {        
        for(int i = 0,j=s.length()-1 ;i <=j; i++,j-- )
        {
            if(s.charAt(i)!=s.charAt(j))return false;
        }
        return true;
    }
    public int superpalindromesInRange(String left, String right) {
        long leftnum = Long.parseLong(left);
        long rightnum = Long.parseLong(right);
        int counter=0;
        for(int i = 0 ; i < 99999; i++)
        {
            int j = 0;
            String istr = String.valueOf(i);
            String ipalineven = istr;
            for(int k = istr.length()-1; k>=0; k--)
                ipalineven += istr.charAt(k);
            long ipalinevennum = Long.parseLong(ipalineven);
            long ipalinevennumsquare =  ipalinevennum * ipalinevennum ;
            if(ipalinevennumsquare >= leftnum &&  ipalinevennumsquare <= rightnum && isPalindrome(String.valueOf(ipalinevennumsquare)))counter++;
            
            String ipalinodd = istr;
            for(int k = istr.length()-2; k>=0; k--)
                ipalinodd += istr.charAt(k);
            long ipalinoddnum = Long.parseLong(ipalinodd);
            long ipalinoddnumsquare =  ipalinoddnum*ipalinoddnum;
            if( ipalinoddnumsquare >= leftnum &&   ipalinoddnumsquare <= rightnum && isPalindrome(String.valueOf( ipalinoddnumsquare)))counter++;
            
        }
        
//         long i = (long)Math.sqrt(leftnum);
        
//         for(; i * i < leftnum; i++);
//         for(;i*i<=rightnum; i++)
//         {
//             if(isPalindrome(String.valueOf(i)) && isPalindrome(String.valueOf(i*i)))counter++;
//         }
        return counter;
    }
}