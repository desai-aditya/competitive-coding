class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> m;
        for ( auto el: candyType)m[el]++;
        return min(candyType.size()/2,m.size());
    }
};