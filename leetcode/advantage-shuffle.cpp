class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //sort(A.begin(),A.end());
        multiset<int> s;
        for(auto e:A)s.insert(e);
        
        vector<int> ans(A.size(),INT_MAX),rem;
        
        for(int i = 0 ; i < B.size() ; i++)
        {
            auto itr = s.lower_bound(B[i]+1);
            if(itr!=s.end())
            {
                ans[i] = *itr;
                s.erase(itr);                
            }
            else
            {
                rem.push_back(i);
            }

        }
        auto itr = s.begin();
        for(int i = 0 ; i < rem.size() ; i ++)
        {
            //if(ans[i]==INT_MAX){
                ans[rem[i]]=*itr;
                itr++;
                //s.erase(s.begin());
            //}
        }
        return ans;
            
    }
};