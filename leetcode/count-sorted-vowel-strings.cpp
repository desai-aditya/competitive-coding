class Solution {
public:
    int countVowelStrings(int n) {
        long long int arr[51][5];
        for(int i =  1;  i <= 50; i++ )
        {
            long long sum = 0;
            for(int j = 0 ; j < 5 ; j ++)
            {
                if(i==1)arr[i][j]=1;
                else
                {
                    sum+=arr[i-1][j];
                    arr[i][j]=sum;
                }
            }
        }
        return arr[n][0]+arr[n][1]+arr[n][2]+arr[n][3]+arr[n][4];
        
    }
};