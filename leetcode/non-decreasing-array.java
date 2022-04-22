class Solution {
    public boolean checkPossibility(int[] nums) {
        int counter1 = 0, counter2=0;
        int tempnum=nums[0], tempnumindex=0;
        
        for(int i = 0 ; i < nums.length -1 ; i++)
        {
            if(nums[i] > nums[i+1] ){
                tempnum = nums[i];
                tempnumindex = i;
                nums[i]=nums[i+1];
                
                break;
            }
        }
        for(int i = 0 ; i < nums.length -1 ; i++)
        {
            if(nums[i] > nums[i+1] ){
                counter1++;
                break;
            }
        }
        nums[tempnumindex]=tempnum;
        if(tempnumindex<nums.length-1)
        {
            nums[tempnumindex+1]=nums[tempnumindex];
        }
        for(int i = 0 ; i < nums.length -1 ; i++)
        {
            if(nums[i] > nums[i+1] ){
                counter2++;
                break;
            }
        }
        
        
        
        if(counter1 == 1 && counter2 == 1)return false;
        return true;
    }
    
}