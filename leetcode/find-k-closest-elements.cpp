class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first<b.first)return 1;
        if(a.first==b.first && a.second < b.second)return 1;
        return 0;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int> > v =vector<pair<int,int> > () ;
        for(int i  = 0; i < arr.size(); i++)
        {
            v.push_back({abs(arr[i]-x),arr[i]});
            
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans = vector<int>();
        for(int i = 0 ; i < k ; i ++)
        {
            ans.push_back(v[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};