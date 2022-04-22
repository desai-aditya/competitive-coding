class Solution {
    public Integer BinToInt(String s)
    {
        int num = 0;
        for(int i  = s.length()-1 ; i >=0; i--)
        {
            num*=2;
            num += s.charAt(i)-'0';
            
        }
        return num;
    }
    public List<Integer> grayCode(int n) {
        String s = "0";
        ArrayList<String> strs = new ArrayList<String>();
        int k=2;
        strs.add("0");strs.add("1");
        for(int i  = 2 ; i <= n ; i ++)
        {
            for(int j  = k-1 ; j >=0  ; j --)
            {
                String t = strs.get(j);
                strs.set(j,"0"+t);
                strs.add("1"+t);
            }
            k*=2;
        }
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for(int i = 0 ; i < strs.size(); i++)
        {
            System.out.println(strs.get(i));
            ans.add(BinToInt(strs.get(i)));
        }
        
        return ans;
    }
}