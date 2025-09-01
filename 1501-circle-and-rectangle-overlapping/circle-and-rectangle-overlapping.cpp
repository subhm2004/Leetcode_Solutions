class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1,
                      int x2, int y2) {
        int left = min(x1, x2);
        int right = max(x1, x2);

        int top = max(y1, y2);
        int bottom = min(y1, y2);
        
        
        int x_close = max(left , min(xc,right));
        int y_close = max(bottom , min(yc,top));
        
        
        int dx = x_close - xc ;
        int dy = y_close - yc;
        
        
        return dx*dx + dy*dy <= r*r;
    }
};