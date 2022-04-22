class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> l,r;
        int lp = -1,rp=-1;
        r=vector<int>(dominoes.size());

        for(int i = 0 ; i < dominoes.size() ; i++)
        {
            if(dominoes[i]=='R')rp=i;
            else if(dominoes[i]=='L')rp=-1;
            else if(dominoes[i]=='.'&&rp!=-1)
            {
                r[i]=(i-rp);
                continue;
            }
            r[i]=(INT_MAX);
        }
        l=vector<int>(dominoes.size());
        
        for(int i = dominoes.size()-1 ; i >= 0 ; i--)
        {
            if(dominoes[i]=='L')lp=i;
            else if(dominoes[i]=='R')lp=-1;
            else if(dominoes[i]=='.'&&lp!=-1)
            {
                l[i]=(lp-i);
                continue;
            }
            l[i]=(INT_MAX);
        }
        
        string ans = "";
        for(int i = 0 ; i < dominoes.size() ; i++)
        {
            if(dominoes[i]=='R')ans+='R';
            else if(dominoes[i]=='L')ans+='L';
            else if(dominoes[i]=='.')
            {
                if(l[i]<r[i]&&l[i]!=INT_MAX)ans+='L';
                else if(l[i]>r[i]&&r[i]!=INT_MAX)ans+='R';
                else ans+='.';
            }
        }
       
        return ans;
    }
};