class Solution {
    private boolean isVowel(Character c)
    {
        return c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' ;
    }
    public boolean halvesAreAlike(String s) {
        s= s.toLowerCase();
        int count = 0;
        for(int i = 0 ; i  < s.length()/2; i++)
        {
            if(isVowel(s.charAt(i)))
            {
                count++;
            }
        }
        for(int i = s.length()/2; i  <s.length(); i++)
        {
            if(isVowel(s.charAt(i)))
            {
                count--;
            }
        }
        return count==0;
    }
}