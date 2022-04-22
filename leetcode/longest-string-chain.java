class Solution {
    public void prints(String[] words)
    {
        for(String e : words)
        {
            System.out.print(e+" ");
        }
        System.out.println();
    }
    public int longestStrChain(String[] words) {
        Arrays.sort(words,(as,bs)->{
            if(as.length()!=bs.length())
                return as.length() - bs.length();
            else
                return as.compareTo(bs);
        });
        // prints(words);
        HashMap<String,Integer> m = new HashMap<String,Integer>();
        String alphs = "abcdefghijklmnopqrstuvwxyz";
        //System.out.println(alphs.substring(1,1));
        int ans=1;
        for(int i = 0; i< words.length ; i++)
        {
            String t = words[i].substring(1);
            //System.out.println(t);
            int temp=1;
            if(m.get(t)!=null)
            {
                temp = Math.max(temp,m.get(t)+1);
            }
            for(int j = 1 ; j < words[i].length()-1; j++)
            {
               t =  words[i].substring(0,j) + words[i].substring(j+1,words[i].length());
                //System.out.println(t);
                if(m.get(t)!=null)
                {
temp = Math.max(temp,m.get(t)+1);                   
                }
            }
            t = words[i].substring(0,words[i].length()-1);
            //System.out.println(t);
            if(m.get(t)!=null)
            {
temp = Math.max(temp,m.get(t)+1);                
            }
            
            
                m.put(words[i],temp);
            
            //System.out.println(m.get(words[i]));
            ans = Math.max(m.get(words[i]),ans);            
        }
        return ans;
    }
}