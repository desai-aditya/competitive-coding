class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character,Character> m = new HashMap<Character,Character>();
        
        for(int i = 0 ; i < s.length(); i ++)
        {
            
            if(m.get(s.charAt(i))==null)
            {
                if(m.containsValue(t.charAt(i)))return false;
                m.put(s.charAt(i),t.charAt(i));
            }
            else 
            {
                if(Character.valueOf(m.get(s.charAt(i))).compareTo(Character.valueOf(t.charAt(i)))!=0)return false;
            }
        }
        return true;
        
    }
}