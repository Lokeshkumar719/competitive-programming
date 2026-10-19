class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // if distance of nearest point on rectangle is <= r then true else false
        
        int xi,yi;
        if(x1 > xCenter){
            xi = x1;
        }else if(x2 < xCenter){
            xi = x2;
        }else{
            xi = xCenter;
        }

        if(y1 > yCenter){
            yi = y1;
        }else if(y2 < yCenter){
            yi = y2;
        }else{
            yi = yCenter;
        }

        return (xCenter-xi)* (xCenter-xi) + (yCenter-yi)*((yCenter-yi)) <= radius*radius;

    }
};