class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;  // 5 bills ka count
        int ten  = 0;  // 10 bills ka count

        for(int &bill : bills) {
            if(bill == 5) {
                five++;  // 5 bill ke liye koi change nahi chahiye, bas 5 ka count badhao
            } else if(bill == 10) {  // 10 bill ke liye 5 ka change dena hai
                if(five > 0) {  // Agar 5 bill hai toh change de sakte hain
                    five--;  // 5 ka bill de diya
                    ten++;   // 10 ka bill ab increase karna hai
                } else {
                    return false;  // Agar 5 bill nahi hai, toh change nahi de sakte
                }
            } else if(five > 0 && ten > 0) {  // 20 bill ke liye 15 ka change dena hai
                five--;  // Ek 5 ka bill dena hoga
                ten--;   // Ek 10 ka bill dena hoga
            } else if(five >= 3) {  // Agar 10 + 5 nahi de sakte, toh teen 5 ka bill dena hoga
                five -= 3;  // 5 ke 3 bills de diye
            } else {
                return false;  // Agar 15 ka change nahi de pa rahe, toh return false
            }
        }

        return true;   
    }
};
