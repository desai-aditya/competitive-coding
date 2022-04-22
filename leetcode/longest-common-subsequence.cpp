class Solution {
public:
    map< pair<int,int> , int> m;
    int _helper(string &s1, string &s2, int i , int j)
    {
        if(s1.size()==i||s2.size()==j)return 0;
        if(m.find({i,j})!=m.end())return m[{i,j}];
        int ans = 0;
        if(s1[i]==s2[j])
        {
            //cout<<s1<<endl<<s2<<endl;
            ans= 1+_helper(s1,s2,i+1,j+1);
        }
        else
        {
            ans= max(_helper(s1,s2,i+1,j),_helper(s1,s2,i,j+1));
        }
        m[{i,j}]=ans;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        m={};
        return _helper(text1, text2, 0 , 0);
    }
};