class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> arr(n);
        arr[0]=1;
        int tk = k;
        int flag=1;
        for(int i = 1 ; i < n; i++)
        {
            int f=0;
            while(k)
            {
                if(flag)
                    arr[i]=arr[i-1]+k;
                else
                    arr[i]=arr[i-1]-k;
                flag=!flag;
                k--;
                i++;
                f=1;
            }
            if(i>=n)break;
            if(f==0)
                arr[i]=arr[i-1]+1;
            else
                arr[i]=arr[1]+1;
        }
        return arr;
        
    }
};