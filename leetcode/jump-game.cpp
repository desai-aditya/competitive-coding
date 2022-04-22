class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_possible = 0;
        int go_till = 0;
        int i =0;
        while(i<nums.size()&&i<=go_till)
        {
            go_till = max(go_till,nums[i]+i);
            i++;
        }
        return i==nums.size();
    }
};