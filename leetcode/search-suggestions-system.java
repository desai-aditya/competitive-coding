class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        String s = "";
        Arrays.sort(products);
        List<List<String> > ans = new ArrayList<List<String>>();
        for(int i = 0 ; i < searchWord.length(); i++)
        {
            s += searchWord.charAt(i);
            
            List<String> l = new ArrayList<String>();
            for(int j = 0 ; j < products.length; j++)
            {
                if(products[j].startsWith(s))l.add(products[j]);
                if(l.size()>=3)break;
            }
            ans.add(l);
        }
        return ans;
    }
}