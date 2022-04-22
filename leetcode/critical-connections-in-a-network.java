class Solution {
    ArrayList<ArrayList<Integer>> g;
    List<List<Integer> > bridges;
    int timer = 0;
    
    public void getBridges(int[] low,int[] disc,int[] vis,int[]par, int u, int p)
    {
        vis[u]=1;
        par[u]=p;
        disc[u] = timer;
        low[u]  = timer;
        timer++;
        
        for(int el : g.get(u))
        {
            if(vis[el]==0)
            {
                getBridges(low,disc,vis,par,el,u);
                
                low[u] = Math.min(low[u],low[el]);                                
            }
            else if(p != el)
            {
                low[u] = Math.min(low[u],disc[el]);
            }
            
            if(low[el] > disc[u])
            {
                ArrayList<Integer> a = new ArrayList<Integer>();
                a.add(u);
                a.add(el);
                bridges.add(a);
            }
        }
    }
    
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        g = new ArrayList<ArrayList<Integer>>();
        bridges = new ArrayList<List<Integer>>();
        timer = 0;
        for(int i = 0 ; i < n; i++)
        {
            ArrayList<Integer> a  = new ArrayList<Integer>();
            g.add(a);
        }
        for(int i = 0 ; i < connections.size() ; i++)
        {
            int u = connections.get(i).get(0);
            int v = connections.get(i).get(1);
            g.get(u).add(v);
            g.get(v).add(u);
        }
        
        int[] low = new int[n];
        int[] disc= new int[n];
        int[] par = new int[n];
        int[]vis = new int[n];        
        
        for(int i  = 0; i < n; i++)
        {
            if(vis[i]==0)
                getBridges(low,disc,vis,par,i,i);
        }
        
        
        return bridges;
    }
}