class Solution {
private:
    double radius;              // Circle ki radius store karte hain
    double x_center, y_center;  // Circle ke center ke coordinates

public:
    // Constructor - circle ki properties set karta hai
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;         // Radius assign kar rahe hain
        this->x_center = x_center;     // Center ka x coordinate
        this->y_center = y_center;     // Center ka y coordinate
    }
    
    // Main function - circle ke andar random point generate karta hai
    vector<double> randPoint() {
        // Step 1: Random angle generate karna (0 se 2π tak)
        // rand()/RAND_MAX se 0-1 ke beech number milta hai, usse 2π se multiply kar rahe hain
        double theta = ((double) rand() / RAND_MAX) * 2 * M_PI;
        
        // Step 2: Random radius generate karna 
        // sqrt() isliye use kar rahe hain taaki points uniformly distributed hों
        // Bina sqrt ke points center ke paas zyada cluster ho jaate hain
        double r = radius * sqrt((double) rand() / RAND_MAX);
        
        // Step 3: Polar coordinates ko Cartesian coordinates mein convert karna
        // cos(theta) se x direction ka component milta hai
        double x = x_center + r * cos(theta);
        
        // sin(theta) se y direction ka component milta hai  
        double y = y_center + r * sin(theta);
        
        // Step 4: Final coordinates return kar rahe hain vector ke form mein
        return {x, y};
    }
};