// https://cses.fi/problemset/task/1068
#include<bits/stdc++.h>

using namespace std;
int main()
{
	long long int n;
	cin >> n;
    while(n!=1)
    {
        cout<<n<<" ";
        if(n%2)
            n=3*n+1;
        else
            n/=2;
        cout.flush();
    }
    cout<<n<<endl;

}
