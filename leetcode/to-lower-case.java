class Solution {
    public String toLowerCase(String s) {
        String a="";
        for(int i=0; i< s.length(); i++)
            {
                int c = (int)s.charAt(i);

            c= c|(1<<5);
            a+= (char) c;
            
            }
        return a;
    }
}