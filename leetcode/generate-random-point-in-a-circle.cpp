class Solution {
public:
    
    double x,y,r;
    Solution(double radius, double x_center, double y_center) {
        x=x_center;
        y=y_center;
        r=radius;
    }
    
    vector<double> randPoint() {
        double xnew,ynew;
        while(!inCircle(xnew,ynew))
        {
            xnew = (double)rand()/RAND_MAX *(r+r)  + x -r;
            ynew = (double)rand()/RAND_MAX *(r+r)  + y -r;
        }
        return {xnew,ynew};
    }
    
    bool inCircle(double xnew, double ynew)
    {
        return  ( (xnew-x)*(xnew-x) + (ynew-y)*(ynew-y) <= r*r   );
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */