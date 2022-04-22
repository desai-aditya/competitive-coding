class Solution {
    
    public List<List<String>> findDuplicate(String[] paths) {
        HashMap<String, ArrayList<String> > m = new HashMap<String, ArrayList<String> > ();
        for(int i = 0 ; i < paths.length; i++)
        {
            String path = "";
            int j=0;
            for(j = 0 ; j < paths[i].length() ; j++)
            {
                if( paths[i].charAt(j) == ' ')break;
                path+= paths[i].charAt(j);
            }
            j++;            
            while(j<paths[i].length())
            {
                String filename = "";
                for(;j<paths[i].length(); j++)
                {
                    if( paths[i].charAt(j) == '(')break;
                    filename +=  paths[i].charAt(j);
                }
                
                j++;
                String content="";
                for(;j<paths[i].length(); j++)
                {
                    if( paths[i].charAt(j) == ')')break;
                    content +=  paths[i].charAt(j);
                }
                j++;j++;
                
                if(m.get(content)==null)
                {
                    ArrayList<String> arr = new ArrayList<String>();
                    m.put(content,arr);
                }
                ArrayList<String> arr = m.get(content);
                arr.add(path+"/"+filename);                
            }
        }
        ArrayList<List<String>> ans = new ArrayList<List<String>>();
        for(Map.Entry<String, ArrayList<String> > entry : m.entrySet()){
            if(entry.getValue().size()>1)
                ans.add(entry.getValue());
        }
        return ans;
    }
}