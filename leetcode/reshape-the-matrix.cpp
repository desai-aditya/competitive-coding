class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int> > ans = vector<vector<int> >(r,vector<int>(c));
        int newi=0,newj=0;
        if(r*c!=mat[0].size()*mat.size())return mat;
        for(int i = 0 ; i < mat.size(); i++)
        {
            for(int j = 0 ; j  <mat[0].size(); j++)
            {
                if(newj>=c){
                    newj=0;
                    newi++;
                }
                ans[newi][newj]=mat[i][j];
                newj++;
            }
        }
        return ans;
    }
};