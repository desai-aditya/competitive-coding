class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sh=0;
        int n=s.size();

        for(int i=0;i<shift.size();i++)
        {
            sh+=  shift[i][0]==1?shift[i][1]:-1*(shift[i][1]);
            cout<<sh<<endl;    
        }
        
        string out={};
        
        cout<<sh<<endl;
        sh=sh%n;
            
        cout<<sh<<endl;
        int start;
        if(sh<0)
        {
            start=sh*-1;
        }
        else
        {
            start=s.size()-sh;
        }
        cout<<start<<endl;
        for(int i=start;i<start+s.size();i++)
        {
            out+=s[i%s.size()];
        }
        
        return out;
        
    }
};