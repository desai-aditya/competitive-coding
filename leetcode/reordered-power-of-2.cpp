class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int n=N;
        map<int,int> m;
        while(N)
            {
                m[N%10]++;
                N/=10;
            }
        for( int i=1; i<=1000000000; i*=2)
            {
                 map<int,int> m2=m;
                 int j=i;
                 while(j)
                     {
                         m2[j%10]--;
                         j/=10;
                     }
                 int f=0;
                 for( auto itr :m2)
                     {
                          if(itr.second!=0)
                              { f=1; break;}
                     
                     
                     }
                 if(f==0) return true;
            }
        return false;
    }
};