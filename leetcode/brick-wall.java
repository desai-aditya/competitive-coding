class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        //ArrayList<HashMap<Integer,Integer> > arrm = new ArrayList<HashMap<Integer,Integer> >();
        int width = 0;
        for(int j = 0 ; j < wall.get(0).size(); j++)
        {
            width+=wall.get(0).get(j);
        }
        
        HashMap<Integer,Integer> bigm = new HashMap<Integer,Integer>();
        
        for(int i = 0 ; i< wall.size(); i++)
        {
            //HashMap<Integer,Integer> tm = new HashMap<Integer,Integer>();
            int sum = 0;
            for(Integer e : wall.get(i))
            {
                sum+=e;
                //tm.put(sum,1);
                if(bigm.get(sum)!=null)
                    bigm.put(sum,(int)bigm.get(sum)+1);
                else
                    bigm.put(sum,1);
            }
            //arrm.add(tm);                
        }
        int maxel = 0;
        
        
        Iterator bigmitr = bigm.entrySet().iterator();
        while(bigmitr.hasNext())
        {
            Map.Entry mapEntry = (Map.Entry )bigmitr.next();
            if((int)mapEntry.getKey() == width)continue;
            // int sum = 0;
            // for(int i = 0 ; i< wall.size(); i++)
            // {                
            //     HashMap<Integer,Integer> tm = arrm.get(i);
            //     if(tm.get(mapEntry.getKey())!=null)
            //     {
            //         sum++;
            //     }
            // }
            
            maxel = Math.max(maxel,(int)mapEntry.getValue());
            
        }
        return wall.size() - maxel;
    }
}