class Solution {
    public int maxScore(int[] cardPoints, int k) {
        long  minel = 10000000000l;
        long  sum = 0,totalsum = 0; 
        long  newk = cardPoints.length - k;
        for(long i = 0 ; i < newk && i < cardPoints.length; i++)
        {
            sum+=cardPoints[(int)i];
            totalsum += cardPoints[(int)i];
        }
        minel = Math.min(minel,sum);
        if(cardPoints.length < k)return (int)sum;
        for(long  i = newk ; i < cardPoints.length; i++)
        {
            sum -= cardPoints[(int)(i-newk)];
            sum += cardPoints[(int)i];     
            totalsum += cardPoints[(int)i];
            minel = Math.min(minel,sum);
        }
        return (int)(totalsum - minel);
    }
}