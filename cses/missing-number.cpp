// https://cses.fi/problemset/task/1083j
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> arr(n+1,0);
    
    for(int i = 0; i < n-1 ; i ++)
    {
       int t;
       cin>>t; 
       arr[t]++;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(arr[i]==0)
        {
            cout<<i<<endl;
            break;
        }
    }

}

