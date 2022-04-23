class Solution {
public:
    int prevColor;
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int valid(int newx,int newy,int n, int m)
    {
        return newx>=0 && newx <n && newy >=0 && newy<m ;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = sr+dx[i];
            int newy = sc +dy[i];
            if(valid(newx,newy,image.size(),image[0].size()) && image[newx][newy]==prevColor)
            {
                image[newx][newy]=newColor;
                dfs(image,newx,newy,newColor);
            }
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        prevColor = image[sr][sc];
        if(prevColor == newColor)return image;
        image[sr][sc]=newColor;
        dfs(image,sr,sc,newColor);
        return image;
    }
};