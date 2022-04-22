class WordFilter {
    private HashMap<String, ArrayList<Integer> > prem,sufm;
    private HashMap<String, Integer > mfinal;
    public WordFilter(String[] words) {
        mfinal = new HashMap<String, Integer >();
        for(int k = 0 ; k < words.length; k++)
        {
            String s = "#";
            for(int i = 0 ; i < words[k].length(); i++)
            {
                s = s + words[k].charAt(i);
                String st = s;
                for(int j = words[k].length()-1; j>=0; j--)
                {
                    st = words[k].charAt(j) + st;
                    mfinal.put(st,k);
                }
            }
            
        }
    }
    
    public int f(String prefix, String suffix) {
        String s = (suffix);
        s =s + "#";
        s = s + prefix;
        
        if(mfinal.get(s)!=null)
            return mfinal.get(s);
        return -1;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */