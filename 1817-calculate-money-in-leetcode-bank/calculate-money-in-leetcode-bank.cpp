class Solution {
public:
    int totalMoney(int n) {
        int total_money = 0;
        int monday_money = 1;  // Pehle Monday ko 1 ₹ milenge
        
        for (int day = 0; day < n; day++) {
            total_money += monday_money + (day % 7);  // Har din ka paisa add karna hai
            
            // Agar week ka last day (Sunday) aagaya, toh next Monday ke liye paisa badha do
            if (day % 7 == 6) {
                monday_money++;
            }
        }
        
        return total_money;  
    }
};
