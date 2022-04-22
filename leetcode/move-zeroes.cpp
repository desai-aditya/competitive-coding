class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroptr=0;int numptr=0;
        int n = nums.size();
        
 while(1)
     {
     while(numptr< n && nums[numptr]==0 && numptr<n)numptr++;
 
                while(zeroptr<n&&nums[zeroptr]!=0 && zeroptr<n)zeroptr++;
 //cout<<numptr<< " "<<zeroptr<<endl;
     if(zeroptr>=n || numptr>=n)break;
     if(numptr>zeroptr)
         {
     int t=nums[numptr];
     nums[numptr]=nums[zeroptr];
     nums[zeroptr]=t;
     }
     else{numptr++;}
        }
        
        
    }
};