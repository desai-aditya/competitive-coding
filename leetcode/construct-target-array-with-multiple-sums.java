class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a,b)->(b-a));
        long sum = 0;
        for(int i = 0 ; i < target.length; i++)
        {
            pq.add(target[i]);
            sum+=target[i];
        }
        
        while(pq.size()!=0)
        {
            int t = pq.poll();
            sum-=t;
            if(t==1 || sum == 1)return true;
            if(t < sum || sum == 0 || t%sum == 0)return false;
            t%=sum;
            sum+=t;
            pq.add(t);
        }
        return true;
    }
}