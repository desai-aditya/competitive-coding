int min(int a, int b){return (a<b)?a:b;}
int max(int a,int b){ return (a>b)?a:b;}

int maxArea(int* height, int heightSize){

    int ans=0;
    for(register int i=0; i<heightSize;i++)
        {
            for(register int j=i+1;j<heightSize;j++)
                {
                
                    ans=max(ans,min(height[i],height[j])*(j-i));
                }
        
        }
    return ans;
}