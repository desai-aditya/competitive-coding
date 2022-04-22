// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int l=1,r=n;
        int ans=n;
        while(l<=r)
        {
            int mid = (l-r)/2+r;
            if(isBadVersion(mid))
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
            
        }
        return ans;
        
    }
};