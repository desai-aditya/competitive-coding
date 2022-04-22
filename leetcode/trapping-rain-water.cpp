class Solution {
public:
    int trap(vector<int>& height) {
        height.insert(height.begin(),0);
        height.push_back(0);
        long long int sum=0;
        long long int leftsum=0,rightsum=0;
        int maxel=height[0];
        int l=0,li=0;
        for(int i = 0; i< height.size();i++)
            {
                sum+=height[i];
                if(height[i] > l)
                    {
                    
                    leftsum+=(height[i] - l)*(i);
                    l=height[i];
                    li=i;
                    }
            maxel=max(maxel,height[i]);
             }
        reverse(height.begin(),height.end());
        l=li=0;
        for(int i = 0; i< height.size();i++)

            {

               // sum+=height[i];

                if(height[i] > l)

                    {

                    

                    leftsum+=(height[i] - l)*(i);

                    l=height[i];

                    li=i;

                    }

             }
        return maxel*height.size()-sum-leftsum;
    }
};