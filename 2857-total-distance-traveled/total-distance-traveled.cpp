class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0;   // total distance jo travel hua
        int consumed = 0;   // kitna fuel consume hua hai (5 ka multiple track karne ke liye)
        
        // Jab tak main tank mein fuel hai, chalte raho
        while (mainTank > 0) {
            // 1 liter consume karo main tank se
            mainTank--;
            consumed++;
            
            // 1 liter consume hone se 10 km distance milta hai (mileage = 10 km/liter)
            distance += 10;
            
            // Check karo: agar 5 liters complete ho gaye hain consumption mein,
            // aur additional tank mein fuel available hai (kam se kam 1 liter)
            if (consumed == 5 && additionalTank > 0) {
                additionalTank--;  // additional tank se 1 liter nikalo
                mainTank++;        // main tank mein 1 liter add karo
                consumed = 0;      // counter reset karo, next 5 liters ke liye fresh start
            }
        }
        
        return distance;
    }
};