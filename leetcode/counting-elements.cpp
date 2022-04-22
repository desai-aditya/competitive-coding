class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> m{};
        for(auto el : arr)
        {
            m[el]++;
        }
        
        int count =0;
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            //cout<<itr->first<<" "<<itr->second<<endl;
            
            count+= m[itr->first-1];
        }
        return count;
    }
};