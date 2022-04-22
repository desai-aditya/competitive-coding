class Solution {
    HashMap<String, int[] > m;
    public boolean compare(String w1, String w2)
    {
        int[] arr1 = m.get(w1);
        int[] arr2 = m.get(w2);
        
        for(int i = 0 ; i < 26; i++)
        {
            if(arr1[i]==1 && arr2[i]==1)return false;
        }
        return true;
    }
    public int maxProduct(String[] words) {
        m = new HashMap<String, int[] >();
        
        for(String w : words)
        {
            int[] arr = new int[26];
            Arrays.fill(arr,0);
            for(int i = 0  ;i < w.length(); i++)
            {
                arr[ (int)w.charAt(i) - 97 ]=1;
            }
            m.put(w,arr);
        }
        int ans = 0;
        for(String w1 : words)
        {
            for(String w2 : words)
            {
                if(!w1.equals(w2) && compare(w1,w2))
                {
                    ans = Math.max(ans,w1.length()*w2.length());
                }
            }
        }
        return ans;
    }
}