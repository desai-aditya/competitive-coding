class Solution {
public:
    int findComplement(int num) {
        
        int ans=0;
        int counter=0;
        while(num)
        {
            ans+= (((num%2)?0:1)<<counter);
          // cout << (((num%2)?0:1)<<counter);;
            num= num>>1;
            counter++;
        }
        return ans;
    }
};