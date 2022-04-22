class Solution {
public:
    bool isAlpha(char c){return (c<='z'&&c>='a') || (c>='A'&&c<='Z');}
    vector<string> ans;
    void helper(string str, int index, string& temp)
    {
        if(index>=str.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        temp += str[index];
        helper(str,index+1,temp);
        temp.pop_back();
        
        if(isAlpha(str[index]))
        {
            temp += (str[index]^32);
            helper(str,index+1,temp);
            temp.pop_back();
        }
        
    }
    vector<string> letterCasePermutation(string S) {
        ans.clear();
        string temp = "";
        helper(S,0,temp);
        return ans;
    }
};