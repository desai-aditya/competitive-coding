class Solution {
    HashMap<Character,ArrayList<Character> > m= new HashMap<Character,ArrayList<Character> >();;
    List<String> ans;
    public void recurse(String digits, Integer index, String temp)
    {
        if(index>=digits.length())
        {
            ans.add(temp);
            return;
        }
        
        List<Character> nl = m.get(digits.charAt(index));
        for(int i = 0; i < nl.size(); i++)
        {
            Character c = nl.get(i);
            recurse(digits,index+1,temp+Character.toString(c));            
        }
    }
    
    public void makeMap()
    {                                        
        m.put('2',new ArrayList<Character>(Arrays.asList('a','b','c')));                                
        m.put('3',new ArrayList<Character>(Arrays.asList('d','e','f')));                                
        m.put('4',new ArrayList<Character>(Arrays.asList('g','h','i')));                                
        m.put('5',new ArrayList<Character>(Arrays.asList('j','k','l')));                                
        m.put('6',new ArrayList<Character>(Arrays.asList('m','n','o')));                                
        m.put('7',new ArrayList<Character>(Arrays.asList('p','q','r','s')));                                     
        m.put('8',new ArrayList<Character>(Arrays.asList('t','u','v')));                                
        m.put('9',new ArrayList<Character>(Arrays.asList('w','x','y','z')));
        
    }
    public List<String> letterCombinations(String digits) {                        
        makeMap();        
        ans = new ArrayList<String>();
        if(!digits.equals(""))
        {
            recurse(digits,0,"");               
        }        
        return ans;
    }
}