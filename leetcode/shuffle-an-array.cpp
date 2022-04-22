class Solution {
public:
    vector<int> org;
    vector<int> cur;
    Solution(vector<int>& nums) {
        org = nums;
        cur=org;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(cur.begin(),cur.end());
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */