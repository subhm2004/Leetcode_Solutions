class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long prefixSum = 0, result = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];  // Sum of elements from index 0 to i
            long ceilAvg = (prefixSum + (i + 1) - 1) / (i + 1); // Ceil division
            result = max(result, ceilAvg); // Track the maximum min value
        }

        return result;
    }
};


// class Solution {
// public:
//     // yeh helper function check karta hai ki kya given maxVal ke saath 
//     // array ko iss tareeke se modify kiya ja sakta hai ki sabhi elements 
//     // maxVal se chhote ya barabar ho jayein.
//     bool helper(vector<int>& nums, int maxVal) {
//         long extra = 0;
//         // array ke last se traverse karte hain aur check karte hain ki 
//         // kya hum extra values ko peeche bhej sakte hain.
//         for (int i = nums.size() - 1; i > 0; --i) {
//             extra = max(0L, extra + nums[i] - maxVal);
//         }
//         // agar first element ke saath bhi maxVal maintain ho raha hai to true return karte hain.
//         return nums[0] + extra <= maxVal;
//     }

//     // yeh function minimum possible maximum value find karta hai 
//     // jisse array ko modify karne par har element maxVal se chhota ya barabar ho sake.
//     int minimizeArrayValue(vector<int>& nums) {
//         int left = 0, right = *max_element(nums.begin(), nums.end());

//         // binary search ka use karke minimum maxVal dhoondte hain.
//         while (left < right) {
//             int mid = (left + right) >> 1;
//             if (helper(nums, mid))
//                 right = mid; // agar possible hai to maxVal ko aur kam karne ki koshish karte hain.
//             else
//                 left = mid + 1; // agar nahi ho sakta to left ko badhate hain.
//         }

//         return left; // final minimized max value return karte hain.
//     }
// };
