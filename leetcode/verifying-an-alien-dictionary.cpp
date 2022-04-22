class Solution {
public:
    unordered_map<char,int> m1;
    unordered_map<int,char> m2;

    static bool compfunc(vector<int> &a,vector<int> &b)
    {
        int i;
        for(i=0;i<a.size() && i<b.size();i++)
            {
                 if(b[i]<a[i])return false;
                 if(b[i]==a[i])continue;
                 if(b[i]>a[i])return true;
            }
        if(a.size()>i)return false;
        return true;

    }
    void makemap(string& order)
    {
        for(int i=0;i<order.size();i++)
        {
            m1[order[i]]=i;
            m2[i]=order[i];
            //cout<<m2[i]<<" "<<m1[order[i]]<<endl;
        }                
    }
    
    bool isAlienSorted(vector<string>& words, string order) {        
        vector<string> newv;
        makemap(order);
        vector<vector<int> > newvecint;
        for(int i = 0 ; i < words.size(); i++)
        {
            vector<int> t;
            for(auto e:words[i])
            {
                t.push_back(m1[e]);
                cout<<m1[e]<<",";
            }
            cout<<endl;
            newvecint.push_back(t);
        }
        sort(newvecint.begin(),newvecint.end(),compfunc);
        for(int i = 0 ; i < newvecint.size(); i++)
        {
            string t;
            for(auto e:newvecint[i])
            {
                t+=m2[e];
            }
            newv.push_back(t);
        }
        
        
        for(int i=0;i<words.size();i++)
        {
            cout<<newv[i]<<endl;
            if(words[i].compare(newv[i])!=0)
                return false;
        }
        return true;
        
    }
};