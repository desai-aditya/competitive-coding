/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int j = dim[1]-1;
        int i = 0;
        while(j>=0 && i<dim[0])
        {
            if(binaryMatrix.get(i,j))
            {
                
                j--;
            }
            else
            {
                
                i++;
            }
        }
        if(i==dim[0]&&j==dim[1]-1)return -1;
        return max(j+1,0);
    }
};