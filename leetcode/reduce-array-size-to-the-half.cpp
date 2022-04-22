class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector< pair<int,int> > v = {};
        map<int,int> m = {};
        for( int i= 0; i < arr.size(); i++)
            {
            m[arr[i]]++;
            }
        for( auto i: m)
            {
            v.push_back({i.first,i.second});
            }
        
        sort(v.begin(),v.end(),[](auto a,auto b){return a.second<b.second;});
        int ans = 0;
        int count = 0;
        for(int i = v.size()-1;i>=0;i--)
        {
            count+=v[i].second;
            ans++;
            if(count>=arr.size()/2)break;
        }
        return ans;
        
    }
};