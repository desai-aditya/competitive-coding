class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string str1{},str2{};
        
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='#'){if(str1.size())str1.pop_back();}
            else str1+=S[i];
            
            }
         for(int i=0;i<T.size();i++)
        {
            if(T[i]=='#'){if(str2.size())str2.pop_back();}
            else str2+=T[i];
            
            }
        
        return str1==str2;
    }
};