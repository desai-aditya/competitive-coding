class Solution {
    public int minPartitions(String n) {
        int m = -1;
        for(int i = 0 ; i < n.length(); i++ )
        {
            m = Math.max(m,Integer.parseInt(""+n.charAt(i)));
        }
        return m;
    }
}