int arr[67108865];
int visited[67108865];
int visitcounter = 0;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        visitcounter++;
        
        for(int i = 0 ; i<nums.size(); i++)
        {
            
            
            if(nums[i]<0)continue;
            
            
            int index = nums[i]/32;
            int bit = nums[i]%32;
            int one = 1<<bit;
            
            if(visited[index] != visitcounter)
            {
                visited[index]=visitcounter;
                arr[index] = 0;
            }
            
            
            //cout<<arr[index]<< " " << (arr[index]|one)  <<endl;

            arr[index]|=one;
            
        }
        
        for(int i = 0 ; i < 67108865;i++)
        {
            for(int j = (i==0?1:0) ; j<32 ; j++)
            {
                if((arr[i] & (1<<j) )== 0)
                {
                    return i*32+j;
                }

            }
        }
        
        return 1;
    }
};