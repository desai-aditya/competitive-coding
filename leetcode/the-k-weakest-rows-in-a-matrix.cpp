class Solution {
public:
    
    int getsoldiers(vector<vector<int>>& mat, int index)
    {
        int s = mat[index].size()/2;
        if(mat[index][s])
        {
            while( s<mat[index].size()&& mat[index][s])s++;
        }
        else
        {
            while(s>=0 && !mat[index][s])s--;
            s++;
        }
        return s;
    }
    
    static bool compfn(pair<int,int> p1, pair<int,int> p2)
    {
        return (p1.second<p2.second) || (p1.second == p2.second && p1.first < p2.first);
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int> > v(mat.size(),{0,0});
        
        for(int i =  0;  i < mat.size(); i++)
        {
            v[i] = {i,getsoldiers(mat,i)};
            //cout<<v[i].second<<endl;
        }
        
        sort(v.begin(),v.end(),compfn);
        vector<int> ans(k,0);
        for(int i  =  0 ; i < k ; i ++)
        {
            ans[i] = v[i].first;
        }
        return ans;
    }
};