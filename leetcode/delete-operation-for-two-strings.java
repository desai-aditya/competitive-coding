class Solution {
    public HashMap<String,Integer> m = new HashMap<String,Integer>();
    public int lcs(String s1, String s2)
    {
        if(s1.equals("") || s2.equals(""))return 0;
        if(m.get(s1+"#"+s2)!=null)return m.get(s1+"#"+s2);
        if(s1.charAt(s1.length()-1) == s2.charAt(s2.length()-1))
        {
            //System.out.println("hey");
            int val = lcs(s1.substring(0,s1.length()-1),s2.substring(0,s2.length()-1));
            m.put(s1+"#"+s2,1+val);
            return 1 + val;
        }
        else
        {
            int val1 = lcs(s1.substring(0,s1.length()),s2.substring(0,s2.length()-1));
            int val2 = lcs(s1.substring(0,s1.length()-1),s2.substring(0,s2.length()));
            m.put(s1+"#"+s2,Math.max(val1,val2));
            return Math.max(val1,val2);                        
        }
    }
    public int minDistance(String word1, String word2) {
        int val = lcs(word1,word2);
        //System.out.println(val);
        return word1.length() - val + word2.length() - val;
    }
}