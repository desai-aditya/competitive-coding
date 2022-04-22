class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        HashSet<Integer> s = new HashSet<Integer>();
        int numx =1;

        for(int i = 0 ; numx < 1000000 && i < 20; i ++ )
        {
            int numy = 1;
            for(int j = 0 ;  numy < 1000000 && j < 20; j++)
            {

                if( numx + numy >=0 && numx + numy <= bound)
                {
                    s.add(numx+numy);
                }
                numy*=y;
            }
            numx*=x;
        }
        ArrayList<Integer> ans = new ArrayList<Integer>(s);

        return ans;

    }
}