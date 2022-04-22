class Solution {
public:
    
    pair<int,long long int> helper(string& S, int curindex)
    {
        curindex++;
        long long int ans = 0;
        while(S[curindex]!=')')
        {
            pair<int,long long int> temp = helper(S,curindex);
            ans+=temp.second;
            curindex = temp.first;
            curindex++;
        }
        return {curindex,(ans==0)?1:2*ans};
    }
    
    int scoreOfParentheses(string S) {
        S = "("+S+")";
        pair<int,long long int> ans = helper(S,0);
        return ans.second/2;
    }
};