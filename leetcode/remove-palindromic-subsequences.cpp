class Solution {
public:
    bool isPalin(string & s)
    {
        int l = 0;
        int r = s.size()-1;
        while(l<=r)
        {
            if(s[l]!=s[r])return false;
            l++;r--;
        }
        return true;
        
    }
    int removePalindromeSub(string s) {
        if(s=="")return 0;
        if(isPalin(s))return 1;
        return 2;
        
    }
};