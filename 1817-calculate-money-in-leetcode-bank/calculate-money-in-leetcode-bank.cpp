class Solution {
public:
    int totalMoney(int n) {
        int totalMoney = 0;
        int mondayMoney = 1;  // Pehle Monday ko 1 rupay milenge
        
        for (int day = 0; day < n; ++day) {
            totalMoney += mondayMoney + (day % 7);  // Har din ka paisa add karna hai
            
            // Agar week ka last day (Sunday) aagaya, toh next Monday ke liye paisa badha do
            if (day % 7 == 6) {
                ++mondayMoney;
            }
        }
        
        return totalMoney;  // Total jama kiya hua paisa return kar do
    }
};
