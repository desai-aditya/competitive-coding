class Solution {
public:
    int numberOfSteps (int num) {
        int ans=0;
        while(num)
        {
            if(num%2==1)ans++;
            if(num==1)break;
            num/=2;ans++;
            
        }
        return ans;
    }
};