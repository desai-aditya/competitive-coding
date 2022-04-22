class Solution {
    ArrayList<List<String>> ans;
    
    public ArrayList<String> convert(ArrayList<ArrayList<Integer>> m)
    {
        ArrayList<String> c = new ArrayList<String>();
        for(int i = 0 ; i < m.size(); i++)
        {
            String t = "";
            for(int j = 0; j< m.get(i).size(); j++)
            {
                if(m.get(i).get(j)>0)
                {
                    t+='Q';
                }
                else
                {
                    t+='.';
                }
            }
            c.add(t);
        }
        return c;
    }
    public void crossout(ArrayList<ArrayList<Integer> > m, int x, int y,int n)
    {
        for(int i = 0 ; i < n; i++)
        {
            if(m.get(i).get(y)<=0)
            {
                m.get(i).set(y,m.get(i).get(y) -1);
            }
        }
        for(int j = 0 ; j < n; j++)
        {
            if(m.get(x).get(j)<=0)
            {
                m.get(x).set(j,m.get(x).get(j) -1);
            }
        }
        for(int i = x,j=y ; i < n&&j<n; i++,j++)
        {
            if(m.get(i).get(j)<=0)
            {
                m.get(i).set(j,m.get(i).get(j) -1);
            }
        }
        for(int i = x,j=y ; i < n&&j>=0; i++,j--)
        {
            if(m.get(i).get(j)<=0)
            {
                m.get(i).set(j,m.get(i).get(j) -1);
            }
        }
        for(int i = x,j=y ; i >=0&&j<n; i--,j++)
        {
            if(m.get(i).get(j)<=0)
            {
                m.get(i).set(j,m.get(i).get(j) -1);
            }
        }
        for(int i = x,j=y ; i >=0&&j>=0; i--,j--)
        {
            if(m.get(i).get(j)<=0)
            {
                m.get(i).set(j,m.get(i).get(j) -1);
            }
        }                
    }
     
    public void cancelcross(ArrayList<ArrayList<Integer> > m, int x, int y,int n)
    {
        for(int i = 0 ; i < n; i++)
        {
            if(m.get(i).get(y)<0)
            {
                m.get(i).set(y, m.get(i).get(y) +1);
            }
        }
        for(int j = 0 ; j < n; j++)
        {
            if(m.get(x).get(j)<0)
            {
                m.get(x).set(j, m.get(x).get(j) + 1);
            }
        }
        for(int i = x,j=y ; i < n&&j<n; i++,j++)
        {
            if(m.get(i).get(j)<0)
            {
                m.get(i).set(j, m.get(i).get(j) + 1);
            }
        }
        for(int i = x,j=y ; i < n&&j>=0; i++,j--)
        {
            if(m.get(i).get(j)<0)
            {
                m.get(i).set(j, m.get(i).get(j) + 1);
            }
        }
        for(int i = x,j=y ; i >=0&&j<n; i--,j++)
        {
            if(m.get(i).get(j)<0)
            {
                m.get(i).set(j, m.get(i).get(j) + 1);
            }
        }
        for(int i = x,j=y ; i >=0&&j>=0; i--,j--)
        {
            if(m.get(i).get(j)<0)
            {
                m.get(i).set(j, m.get(i).get(j) +1);
            }
        }                
    }
    public void solve(ArrayList<ArrayList<Integer> > m, int count, int n)
    {
        if(n+1==count)
        {
            ans.add(convert(m));
            return;
        }
        
        for(int i = 0 ; i < n ; i ++)
        {
            
            if(m.get(count-1).get(i)==0)
            {
                m.get(count-1).set(i,count);
                crossout(m,count-1,i,n);
                solve(m,count+1,n);
                cancelcross(m,count-1,i,n);
                m.get(count-1).set(i,0);
            }
            
        }
    }
    
    public int totalNQueens(int n) {
        ans = new ArrayList<List<String>>();
        ArrayList<ArrayList<Integer> > m = new ArrayList<ArrayList<Integer> >();
        for(int i = 0 ; i < n ; i ++)
        {
            ArrayList<Integer> r = new ArrayList<Integer>();
            for(int j = 0 ; j < n; j ++)
            {
                r.add(0);
            }
            m.add(r);
        }
        solve(m,1,n);
        return ans.size();
    }
}