class Solution {
    public int countPrimes(int n) {
        int []sieve = new int[n+1];
        Arrays.fill(sieve,1);
        for(int i = 2; i *i <= n; i++)
        {
            if(sieve[i]==1)
            {
                for(int j = i*i ; j <= n ; j+=i )
                {
                    sieve[j]=0;
                }
            }
        }
        int c=0;
        for(int i = 2; i < n ; i++)c+=sieve[i];
        return c;
    }
}