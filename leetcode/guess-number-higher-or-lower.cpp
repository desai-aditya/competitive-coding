/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1;
        int high=n;
        while(low<=high)
            {
               int m=low +(high-low)/2;
               int g=guess(m);
               if(g==0)return m;
               else if (g==1)
                   low=m+1;
               else high=m-1;
            }
        return 0;
    }
};