class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        int prev = heights[0];
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        int sum=0;
        int i;
        for(i = 1; i < heights.length; i++)
        {
            if(heights[i]-prev>0){
                pq.add(heights[i]-prev);                
                if(pq.size()>ladders)    {         
                    sum+= pq.poll();
                    if(sum>bricks)break;                    
                }
            }                
            prev = heights[i];
        }
        return i-1;
    }
}