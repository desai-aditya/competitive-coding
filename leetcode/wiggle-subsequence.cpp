class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int counter = 1;
                
        vector<int> v2;
        
        v2.push_back(nums[0]);
        
        for(int i = 1 ; i < nums.size() ; i ++)
        {
            if( nums[i] != nums [i-1] )
            {
                v2.push_back(nums[i]);
                //cout<<v2[i]<<endl;
            }
        }
        
        
        vector<int> v(v2.size());
        
        v[0]=-1;
        for(int i = 1 ; i < v2.size() ; i ++)
        {
            if(v2[i]<v2[i-1])
            {
                v[i]=-1;
            }
            else if(v2[i]>v2[i-1]) v[i]=1;
            else {
                cout<<v2[i]<<endl;
                v[i]=0;
            }
        }
        if(v.size() >=2 && v[0]==v[1])counter++;
        for(int i = 1 ; i < v.size(); i++)
        {
            //while(i<nums.size()&&v[i]==0)i++;
            //if(i>nums.size())break;
            if(v[i]!=v[i-1])counter++;
        }
        return counter;
        
        
    }
};