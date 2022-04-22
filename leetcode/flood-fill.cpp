class Solution {
public:
    int firstC=-1;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        
        if(!(sr>=0 && sc>=0 && sr<image.size() && sc<image[0].size()))return image;
        
        if(firstC==-1)firstC=image[sr][sc];
        if(image[sr][sc]!=newColor && image[sr][sc]==firstC)
        {
            image[sr][sc]=newColor;
            floodFill(image,sr+1,sc,newColor);
            floodFill(image,sr-1,sc,newColor);
            floodFill(image,sr,sc+1,newColor);
            floodFill(image,sr,sc-1,newColor);
        }
        
        return image;
    }
};