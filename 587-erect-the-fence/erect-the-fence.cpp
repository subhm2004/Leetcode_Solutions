class Solution {
private:
    // ORIENTATION FUNCTION - ye check karta hai ki 3 points ka turn kaisa hai
    // p -> c -> n ke liye:
    // 0 → collinear (same line par hain)
    // 1 → clockwise turn (right turn) 
    // 2 → counterclockwise turn (left turn)
    int orientation(vector<int>& p, vector<int>& c, vector<int>& n) {
        // Cross product formula: (c.y - p.y) * (n.x - c.x) - (c.x - p.x) * (n.y - c.y)
        // Agar positive hai toh clockwise, negative toh counterclockwise, 0 toh collinear
        long long val = 1LL * (c[1] - p[1]) * (n[0] - c[0]) - 
                        1LL * (c[0] - p[0]) * (n[1] - c[1]);
        
        if (val == 0) return 0;        // Collinear - same line par
        return (val > 0) ? 1 : 2;      // 1=clockwise, 2=counterclockwise
    }
    
    // DISTANCE SQUARE FUNCTION - do points ke beech distance ka square
    // Square root nahi lete kyunki comparison ke liye square hi kaafi hai
    long long distSq(vector<int>& a, vector<int>& b) {
        return 1LL * (a[0] - b[0]) * (a[0] - b[0]) + 
               1LL * (a[1] - b[1]) * (a[1] - b[1]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& arr) {
        int n = arr.size();
        
        // EDGE CASE: Agar 1 ya usse kam points hain toh sab return kar do
        if (n <= 1) return arr;
        
        // SPECIAL CASE: Check karo ki sab points collinear hain ya nahi
        // Agar sab ek hi line par hain toh convex hull ki zaroorat nahi
        bool allCollinear = true;
        if (n >= 3) {
            // Pehle 2 points ke saath baaki sab check karo
            for (int i = 2; i < n; i++) {
                if (orientation(arr[0], arr[1], arr[i]) != 0) {
                    // Agar koi bhi point collinear nahi hai toh break
                    allCollinear = false;
                    break;
                }
            }
        }
        
        // Agar sab collinear hain toh sort karke return kar do
        if (allCollinear) {
            sort(arr.begin(), arr.end());  // x ke hisaab se sort
            return arr;
        }
        
        // STEP 1: BOTTOMMOST POINT FIND KARO (GRAHAM SCAN KI SHURUAT)
        // Sabse neeche wala point find karo, agar tie hai toh sabse left wala
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            // Pehle y-coordinate check karo (lower is better)
            if (arr[i][1] < arr[minIdx][1] || 
                // Agar y same hai toh x-coordinate check karo (left is better)
                (arr[i][1] == arr[minIdx][1] && arr[i][0] < arr[minIdx][0])) {
                minIdx = i;
            }
        }
        // Starting point ko 0th position par swap kar do
        swap(arr[0], arr[minIdx]);
        
        // STEP 2: POLAR ANGLE SORTING
        // Sabse neeche wale point (arr[0]) ke relative polar angle ke hisaab se sort karo
        sort(arr.begin() + 1, arr.end(), [&](vector<int>& c, vector<int>& n) {
            // arr[0] se c aur n ka orientation check karo
            int o = orientation(arr[0], c, n);
            
            if (o == 0) {
                // Agar collinear hain toh jo closer hai wo pehle aaye
                return distSq(arr[0], c) < distSq(arr[0], n);
            }
            
            // Counterclockwise (left turn) ko priority do
            return (o == 2); // 2 means counterclockwise
        });
        
        // STEP 3: GRAHAM SCAN ALGORITHM
        // Stack maintain karte hain hull points ka
        vector<vector<int>> hull;
        hull.push_back(arr[0]);  // Starting point add karo
        hull.push_back(arr[1]);  // Second point add karo
        
        // Baaki points ko ek ek karke process karo
        for (int i = 2; i < n; i++) {
            // Jab tak right turn mil raha hai, points ko remove karte raho
            // Right turn matlab clockwise turn, jo convex hull mein nahi chahiye
            while (hull.size() > 1 && 
                   orientation(hull[hull.size()-2], hull[hull.size()-1], arr[i]) == 1) {
                hull.pop_back();  // Last point remove kar do (right turn wala)
            }
            // Current point ko hull mein add kar do
            hull.push_back(arr[i]);
        }
        
        // STEP 4: COLLINEAR POINTS ON BOUNDARY ADD KARO
        // Problem mein fence par sab points chahiye, sirf corners nahi
        
        // Pehle current hull points ko set mein store karo (fast lookup ke liye)
        set<pair<int,int>> hullSet;
        for (auto& p : hull) {
            hullSet.insert({p[0], p[1]});
        }
        
        int hullSize = hull.size();
        
        // Har hull edge ko check karo
        for (int i = 0; i < hullSize; i++) {
            vector<int> current = hull[i];           // Current edge ka start point
            vector<int> next = hull[(i + 1) % hullSize];  // Current edge ka end point
            
            // Saare original points check karo
            for (auto& p : arr) {
                // Agar ye point already hull mein hai toh skip karo
                if (hullSet.find({p[0], p[1]}) == hullSet.end() && 
                    // Aur ye point current edge par collinear hai
                    orientation(current, next, p) == 0) {
                    
                    // Check karo ki point actually edge ke beech mein hai ya nahi
                    // X-coordinate range check
                    if ((p[0] >= min(current[0], next[0]) && p[0] <= max(current[0], next[0])) &&
                        // Y-coordinate range check  
                        (p[1] >= min(current[1], next[1]) && p[1] <= max(current[1], next[1]))) {
                        
                        // Ye point boundary par hai, add kar do
                        hull.push_back(p);
                    }
                }
            }
        }
        
        // Final hull return karo (corner points + boundary collinear points)
        return hull;
    }
};