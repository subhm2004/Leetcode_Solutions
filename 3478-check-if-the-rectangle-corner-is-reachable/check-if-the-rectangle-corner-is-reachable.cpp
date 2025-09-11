typedef long long ll;  

class Solution {
private:
    vector<vector<int>> circles;   
    int xCorner, yCorner;         
    vector<bool> visited;         
    
    // Function: Check karta hai ki koi point (x,y) circle ke andar/boundary par hai ya nahi
    bool in_circle(ll x, ll y, ll cx, ll cy, ll r) {
        // Euclidean distance formula use karte hain: sqrt((x-cx)² + (y-cy)²) <= r
        // Lekin sqrt nahi karte, dono sides square kar dete hain: (x-cx)² + (y-cy)² <= r²
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
    }
    
    // Function: Check karta hai ki circle LEFT boundary (x=0) ya TOP boundary (y=yCorner) ko cross/touch karta hai
    bool cross_Left_Top(ll cx, ll cy, ll r) {
        // Case 1: Left boundary (x=0) ko cross karta hai kya?
        // Circle center se x=0 line tak distance <= radius hona chahiye
        // abs(cx - 0) = abs(cx) <= r (circle left boundary tak pahunchta hai)
        // AND cy >= 0 && cy <= yCorner (circle ka y-coordinate rectangle ke range mein hai)
        bool a = abs(cx-0) <= r && (cy >= 0 && cy <= yCorner);
        
        // Case 2: Top boundary (y=yCorner) ko cross karta hai kya?
        // Circle center se y=yCorner line tak distance <= radius hona chahiye  
        // abs(cy - yCorner) <= r (circle top boundary tak pahunchta hai)
        // AND cx >= 0 && cx <= xCorner (circle ka x-coordinate rectangle ke range mein hai)
        bool b = abs(cy - yCorner) <= r && (cx >= 0 && cx <= xCorner);
        
        // Agar dono mein se koi ek bhi true hai to boundary cross kar raha hai
        return a || b; // OR operator - koi ek condition satisfy hone par true
    }
    
    // Function: Check karta hai ki circle RIGHT boundary (x=xCorner) ya BOTTOM boundary (y=0) ko cross/touch karta hai
    bool cross_Right_Bottom(ll cx, ll cy, ll r) {
        // Case 1: Right boundary (x=xCorner) ko cross karta hai kya?
        // Circle center se x=xCorner line tak distance <= radius hona chahiye
        // abs(cx - xCorner) <= r AND cy rectangle ke y-range [0, yCorner] mein hai
        bool a = abs(cx - xCorner) <= r && (cy >= 0 && cy <= yCorner);
        
        // Case 2: Bottom boundary (y=0) ko cross karta hai kya?
        // Circle center se y=0 line tak distance <= radius hona chahiye
        // abs(cy - 0) = abs(cy) <= r AND cx rectangle ke x-range [0, xCorner] mein hai
        bool b = abs(cy) <= r && (cx >= 0 && cx <= xCorner);
        
        return a || b; // Koi ek bhi condition true hai to boundary cross kar raha hai
    }
    
    // DFS function: Current circle 'i' se start karke check karta hai ki Right/Bottom boundary tak pahunch sakte hain kya
    bool dfs(int i) {
        auto c = circles[i];  // circles[i] ko copy kar lete hain for easy access
        ll x1 = c[0], y1 = c[1], r1 = c[2];  // Current circle ke center coordinates (x1,y1) aur radius r1
        
        // Base case: Agar current circle khud hi Right/Bottom boundary cross karta hai
        // to matlab hum Left/Top se Right/Bottom tak connected path bana diye hain
        if (cross_Right_Bottom(x1, y1, r1)) {
            return true; // Path complete ho gaya, blocking confirmed!
        }
        
        // Current circle ko visited mark kar do taaki infinite loop na ho
        visited[i] = true;
        
        // Saare other circles ko check karo (0 se circles.size()-1 tak)
        for (int j = 0; j < circles.size(); ++j) {
            auto c2 = circles[j];  // j-th circle ka data copy kar lete hain
            ll x2 = c2[0], y2 = c2[1], r2 = c2[2]; // Other circle ke center (x2,y2) aur radius r2
            
            // Agar j-th circle already visited hai to skip kar do (infinite recursion se bachne ke liye)
            if (visited[j]) {
                continue; // Next iteration par jao
            }
            
            // Check karo ki current circle (i) aur j-th circle intersect/touch karte hain kya
            // Distance between centers formula: sqrt((x1-x2)² + (y1-y2)²)
            // Circles intersect karte hain agar: distance <= r1 + r2
            // Square kar dete hain: (x1-x2)² + (y1-y2)² <= (r1+r2)²
            // Ulta condition: agar distance > r1+r2 to intersect nahi karte
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                continue; // Intersect nahi karte, next circle check karo
            }
            
            // CRITICAL OPTIMIZATION: Ye condition ensure karta hai ki circles ka connection rectangle boundary ke andar hai
            // x1*r2 + x2*r1 = weighted average of x-coordinates (r2 aur r1 weights hain)
            // (r1+r2) se divide karne par actual weighted average milta hai
            // Condition: weighted_avg_x < xCorner AND weighted_avg_y < yCorner
            // Matlab connection point rectangle ke andar hona chahiye
            if (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner &&  // X-coordinate valid hai
                y1 * r2 + y2 * r1 < (r1 + r2) * yCorner &&  // Y-coordinate valid hai
                dfs(j)) {  // Recursively j-th circle se aage check karo
                return true;  // Agar j-th circle se Right/Bottom boundary tak path mil gaya to return true
            }
        }
        
        return false;  // Saare connected circles check kar liye, koi path Right/Bottom boundary tak nahi mila
    }
    
public:
    // Main function: Check karta hai ki (0,0) se (xCorner,yCorner) tak path possible hai kya
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        int n = circles.size(); // Total number of circles
        
        // Class ke member variables set kar do
        this->circles = circles;      // Circles array ko class variable mein copy kar do
        this->xCorner = xCorner;      // Rectangle ka width set kar do
        this->yCorner = yCorner;      // Rectangle ka height set kar do
        visited.resize(n, false);     // Visited array ko size n ka bana do, sabko false initialize kar do
        
        // Har circle ke liye individual check karo
        for (int i = 0; i < n; ++i) {
            auto c = circles[i];      // i-th circle ka data copy kar lo
            int x = c[0], y = c[1], r = c[2]; // Center coordinates aur radius extract kar lo
            
            // CRITICAL EARLY CHECK: Agar start point (0,0) ya destination (xCorner,yCorner) 
            // kisi bhi circle ke andar/boundary par hai to path impossible hai
            if (in_circle(0, 0, x, y, r) ||           // Start point circle ke andar hai kya?
                in_circle(xCorner, yCorner, x, y, r)) { // End point circle ke andar hai kya?
                return false; // Path impossible, immediately false return kar do
            }
            
            // MAIN BLOCKING LOGIC:
            // Condition 1: !visited[i] - ye circle abhi tak process nahi hui
            // Condition 2: cross_Left_Top(x, y, r) - ye circle Left/Top boundary ko cross karti hai
            // Condition 3: dfs(i) - is circle se Right/Bottom boundary tak path mil jata hai
            // Agar teeno conditions true hain to BLOCKING PATH ban gaya hai!
            if (!visited[i] &&              // Circle abhi tak visit nahi hui
                cross_Left_Top(x, y, r) &&    // Circle Left ya Top boundary cross karti hai
                dfs(i)) {                   // DFS se Right/Bottom boundary tak path mil jata hai
                return false; // BLOCKING CONFIRMED! Path impossible hai
            }
        }
        
        // Agar saare circles check kar liye aur koi blocking configuration nahi mili
        // to matlab (0,0) se (xCorner,yCorner) tak path possible hai
        return true; // Path exists!
    }
};