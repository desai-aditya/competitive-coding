class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(auto e:nums)sum+=e;
        
        return (nums.size())*(nums.size()+1)/2-sum;
    }
};