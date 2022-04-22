class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)return true;
        
        
        if(coordinates[0][0] == coordinates[1][0])
        {
            for(int i = 0 ; i < coordinates.size(); i++)
            {
                if(coordinates[0][0] != coordinates[i][0])
                {
                    return false;
                }
                
            }
            return true;
        }
        else
        {
            double m = (coordinates[0][1] - coordinates[1][1])/((double)coordinates[0][0] - coordinates[1][0]);
            
            for(int i = 2 ; i < coordinates.size(); i++)
            {
                if((coordinates[0][1] - coordinates[i][1] )!= m*((coordinates[0][0] - coordinates[i][0] )))
                {
                    return false;
                }
                
            }
            return true;
        }
        
    }
};