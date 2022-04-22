class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<int,int> m{};
        
        for(auto el : ransomNote)
        {
            m[el]--;
            
        }
        for(auto el : magazine)
        {
            m[el]++;
            
        }
        
        for(auto itr=m.begin(); itr!=m.end(); itr++)
        {
            if(itr->second<0)return false;
        }
        return true;
        
        
        
    }
};