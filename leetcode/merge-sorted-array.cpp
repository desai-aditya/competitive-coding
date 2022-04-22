class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=nums1.size()-nums2.size();
        
        
        reverse(nums1.begin(), nums1.begin()+i);
        
        i--;
        int j = 0;
        int l=nums1.size()-1;
        while(i>=0 && j<nums2.size())
        {
            nums1[l] = nums1[i]<nums2[j]?nums1[i]:nums2[j];
            if(nums1[l]==nums2[j])j++;
            else i--;
            l--;
        }
        while(i>=0 )
        {
            nums1[l] = nums1[i];
            i--;
            l--;
        }
        while( j<nums2.size())
        {
            nums1[l] = nums2[j];
            j++;
            
            l--;
        }
        
        reverse(nums1.begin(),nums1.end());
        
    }
};