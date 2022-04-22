class Solution {
    public ArrayList<Integer> getArrPat(String s)
    {
        HashMap<Character,Integer> m = new HashMap<Character,Integer>();
        int counter = 0;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i = 0 ; i < s.length() ; i++)
        {
            if( !m.containsKey(s.charAt(i)) )
            {
                m.put(s.charAt(i),counter);
                counter++;
            }
            arr.add(m.get(s.charAt(i)));                        
        }
        return arr;
    }
    
    public boolean matchpat(ArrayList<Integer> a, ArrayList<Integer> b )
    {
        for(int i = 0 ;i <  a.size() ; i ++)
        {
            if(a.get(i)!=b.get(i))return false;
        }
        return true;
    }
    
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        ArrayList<Integer> patarr = getArrPat(pattern);
        List<String> ans = new ArrayList<String>();
        for(int i = 0 ; i < words.length; i++)
        {
            ArrayList<Integer> wordarr = getArrPat(words[i]);
            if(matchpat(wordarr,patarr))
            {
                ans.add(words[i]);
            }
        }
        return ans;
    }
}