class Solution {
    
//     public boolean validate(String s)
//     {
//         int i;
//         for(i = 0 ; i < s.length(); i ++)
//         {
//             if(s.charAt(i)==',')break;
//         }        
//         String xcoor = s.substring(1,i);        
//         if(!String.valueOf(Integer.parseInt(xcoor)).equals(xcoor))return false;        
//         i+=2;
//         String ycoor = s.substring(i,s.length()-1);
//         if(!String.valueOf(Integer.parseInt(ycoor)).equals(ycoor))return false;

//         return true;
//     }    
    public boolean validatestr(String s)
    {
        int i = 0;
        int counter = 0;
        while(i<s.length() && s.charAt(i)=='0')
        {
            i++;counter++;
        }
        if(i==s.length() && counter>=2)return false;
        if(i<s.length())
        {
            if( (s.charAt(i)=='.' || s.charAt(i)==',') && counter>=2)return false;
            if( s.charAt(i) >= '0' && s.charAt(i) <='9' && counter>=1)return false;
        }        
        i=0;
        while(i<s.length() && s.charAt(i)!='.')i++;
        if(i<s.length() && s.charAt(i)=='.')
        {
            i++;
            counter=0;
            while(i<s.length() && s.charAt(i)=='0')
            {
                i++;counter++;
            }
            if(i==s.length())
            {
                return false;                
            }
            
            if(s.charAt(s.length()-1)=='0')return false;
        }        
        return true;
    }
    
    public boolean validate(String s)
    {
        //System.out.println(s);                                
        int i = 1;        
        String xcoor="",ycoor="";        
        while(i<s.length() && s.charAt(i)!=',')
        {            
            xcoor+=s.charAt(i);
            i++;
        }    
        i+=2;
        while(i<s.length() && s.charAt(i)!=')')
        {            
            ycoor+=s.charAt(i);
            i++;
        }
        
        if(!validatestr(xcoor))return false;
        if(!validatestr(ycoor))return false;
        return true;        
    }
    public List<String> ambiguousCoordinates(String s) {
        // System.out.println(String.valueOf((Integer.parseInt("0001"))));
        String comma = ", ";
        String decimal = ".";
        List<String> ans = new ArrayList<String>();
        
        for(int i = 2 ; i < s.length()-1;i++)
        {
            String t = s.substring(0,i) + comma + s.substring(i);
            if(validate(t))
            {
                ans.add(t);
            }
            for(int j = 2 ; j < s.length()-1;j++)
            {
                t = "";
                if(i==j)continue;                
                if(i>j)
                {
                    t = s.substring(0,j) + decimal + s.substring(j,i) + comma + s.substring(i);
                    if(validate(t))                        
                        ans.add(t);
                    
                    for(int k = i+1; k < s.length()-1; k++)
                    {
                        t = s.substring(0,j) + decimal + s.substring(j,i) + comma + s.substring(i,k) + decimal + s.substring(k);
                        
                        if(validate(t))                        
                            ans.add(t);
                    }
                }
                else if(i<j)
                {
                    t = s.substring(0,i) + comma + s.substring(i,j) + decimal + s.substring(j);
                    if(validate(t))  
                        ans.add(t);
                }    
                //System.out.println(t);

            }
        }
        
        return ans;
    }
}