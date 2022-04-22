class Solution {
public:
    string customSortString(string order, string str) {
        int arr[26] = {},m[256]={};
        for(int i=0;i<order.size();i++)
            {
                arr[i]=order[i];
            }
        for(int i = 0; i<str.size(); i++)
            {
            m[str[i]]++;
            }
        string st="";
        for(int i=0;i< order.size();i++)
            {
            for(int j=0;j<m[arr[i]];j++)
       
            st+= arr[i];
                }
        for(int i=0;i<str.size();i++)
            {int flag=0;
            for(int j=0;j<order.size();j++)
                {
                if(str[i]==order[j])
                    flag=1;
                }
             if(!flag)
                 st+=str[i];
            
            }
        return st;
        
    }
};