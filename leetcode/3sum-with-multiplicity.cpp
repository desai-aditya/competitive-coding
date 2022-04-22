class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1000000007;
        sort(arr.begin(),arr.end());
        long long int ans=0;
        for( int i = 0; i< arr.size(); i++)
            {
                 int t= target- arr[i];
                 int j= i+1;
            int k=arr.size()-1;
            
            while(j<k)
                {
                 if( arr[j]+arr[k] < t)
                     j++;
                else if ( arr[j] + arr[k] > t)
                    k--;
                else if( arr[j] + arr[k] == t && arr[j]!=arr[k])
                    {
                        int left=1;
                    int right =1;
                    while( j<k-1 && arr[j]==arr[j+1])
                        {
                        j++;left++;}
                    while( k>j+1 && arr[k]==arr[k-1])

                        {
                        k--;right++;
                        }
                    ans+= left*right;
                    ans%=mod;
                    
                    j++;k--;
                    
                    }
                else{
                    ans+=(k-j+1)*(k-j)/2;
                    ans%=mod;
                    break;
                    }
                
                     
                
                
                
                
                }
            
            
            }
        return ans;
    }
};