class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& arr) {
        // Matrix ke dimensions nikal rahe hain
        int m = arr.size();        // total rows ki count
        int n = arr[0].size();     // total columns ki count
        
        // Result vector banaya hai jo diagonal order store karega
        vector<int> ans;
        ans.reserve(m * n);        // Memory pre-allocate kar rahe hain performance ke liye
        
        // Starting position aur direction variables
        int row = 0, col = 0;      // (0,0) se start kar rahe hain - top-left corner
        bool up = true;            // Direction flag: true = up-right jaa rahe, false = down-left jaa rahe
        
        // Jab tak saare elements process nahi ho jaate
        while (ans.size() < m * n) {
            // Current position ka element answer mein add karo
            ans.push_back(arr[row][col]);
            
            // Agar up-right direction mein move kar rahe hain
            if (up) {
                // UP-RIGHT DIRECTION KE LIYE 3 CASES HAIN:
                
                if (col == n - 1) {
                    // CASE 1: Last column mein pahunch gaye hain
                    // Ab right mein aur nahi jaa sakte, so neeche jaana padega
                    row++;             // Ek row neeche move karo
                    up = false;        // Direction change karo - ab down-left jaayenge
                } 
                else if (row == 0) {
                    // CASE 2: First row mein hain (top boundary)
                    // Ab upar aur nahi jaa sakte, so right jaana padega
                    col++;             // Ek column right move karo
                    up = false;        // Direction change karo - ab down-left jaayenge
                } 
                else {
                    // CASE 3: Normal case - koi boundary nahi hui
                    // Up-right diagonal mein normally move karo
                    row--;             // Ek row upar jao
                    col++;             // Ek column right jao
                    // up flag same rahega (true), direction nahi change hoga
                }
            } 
            else {
                // DOWN-LEFT DIRECTION KE LIYE 3 CASES HAIN:
                
                if (row == m - 1) {
                    // CASE 1: Last row mein pahunch gaye hain (bottom boundary)
                    // Ab neeche aur nahi jaa sakte, so right jaana padega
                    col++;             // Ek column right move karo
                    up = true;         // Direction change karo - ab up-right jaayenge
                } 
                else if (col == 0) {
                    // CASE 2: First column mein hain (left boundary)
                    // Ab left mein aur nahi jaa sakte, so neeche jaana padega
                    row++;             // Ek row neeche move karo
                    up = true;         // Direction change karo - ab up-right jaayenge
                } 
                else {
                    // CASE 3: Normal case - koi boundary nahi hui
                    // Down-left diagonal mein normally move karo
                    row++;             // Ek row neeche jao
                    col--;             // Ek column left jao
                    // up flag same rahega (false), direction nahi change hoga
                }
            }
        }
        
        // Final result return karo jo diagonal order mein elements contain karta hai
        return ans;
    }
};