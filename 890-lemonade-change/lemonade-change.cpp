// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         int five = 0;  // 5 bills ka count
//         int ten  = 0;  // 10 bills ka count

//         for(int &bill : bills) {
//             if(bill == 5) {
//                 five++;  // 5 bill ke liye koi change nahi chahiye, bas 5 ka count badhao
//             } else if(bill == 10) {  // 10 bill ke liye 5 ka change dena hai
//                 if(five > 0) {  // Agar 5 bill hai toh change de sakte hain
//                     five--;  // 5 ka bill de diya
//                     ten++;   // 10 ka bill ab increase karna hai
//                 } else {
//                     return false;  // Agar 5 bill nahi hai, toh change nahi de sakte
//                 }
//             } else if(five > 0 && ten > 0) {  // 20 bill ke liye 15 ka change dena hai
//                 five--;  // Ek 5 ka bill dena hoga
//                 ten--;   // Ek 10 ka bill dena hoga
//             } else if(five >= 3) {  // Agar 10 + 5 nahi de sakte, toh teen 5 ka bill dena hoga
//                 five -= 3;  // 5 ke 3 bills de diye
//             } else {
//                 return false;  // Agar 15 ka change nahi de pa rahe, toh return false
//             }
//         }

//         return true;   
//     }
// };
class Solution {
public:
    bool solve(vector<int>& bills, int i, int five,
                              int ten) {
        if (i == bills.size()) {
            return true;
        }
        int bill = bills[i];

        if (bill == 5) {
            return solve(bills, i + 1, five + 1, ten);
        } else if (bill == 10) {
            if (five > 0) {
                return solve(bills, i + 1, five - 1,
                                            ten + 1);
            }
        } else if (bill == 20) {
            if (ten > 0 && five > 0) {
                return solve(bills, i + 1, five - 1,
                                            ten - 1);
            } else if (five >= 3) {
                return solve(bills, i + 1, five - 3, ten);
            }
        }
        return false;
    }

    bool lemonadeChange(vector<int>& bills) {
        return solve(bills, 0, 0, 0);
    }
};