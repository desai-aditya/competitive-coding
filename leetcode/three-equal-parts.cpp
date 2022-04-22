class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int S = 0;
        vector<int> imp = {-1,-1};
        for(int i = 0 ; i <arr.size(); i++)
        {
            S+=arr[i];
        }
        
        if(S%3!=0)return imp;
        if(S==0)return {0,(int)arr.size()-1};
        int T = S/3;
        int i1,i2,i3,j1,j2,j3;
        i1=j1=i2=j2=i3=j3=-1;
        int count = 0;
        for(int i = 0 ; i < arr.size();  i++)
        {
            if(arr[i]==1)
            {
                count+=1;
            if(count==1)i1=i;
            if(count==T)j1=i;
            if(count==T+1)i2=i;
            if(count==2*T)j2=i;
            if(count==2*T+1)i3=i;
            if(count==3*T)j3=i;
            }
            
        }
        
        
        vector<int> p1;//(arr.begin()+i1,arr.begin()+j1+1);
        vector<int> p2;//(arr.begin()+i2,arr.begin()+j2+1);
        vector<int> p3;//(arr.begin()+i3,arr.begin()+j3+1);
        for(int i = i1 ; i < j1+1;  i++)p1.push_back(arr[i]);
        for(int i = i2 ; i < j2+1;  i++)p2.push_back(arr[i]);
        for(int i = i3 ; i < j3+1;  i++)p3.push_back(arr[i]);

        if(p1!=p2||p1!=p3)return imp;
        int x = i2-j1-1;
        int y = i3-j2-1;
        int z = arr.size()-j3-1;
        if(x<z||y<z)return imp;
        
        return {j1+z,j2+z+1};
        
    }
};