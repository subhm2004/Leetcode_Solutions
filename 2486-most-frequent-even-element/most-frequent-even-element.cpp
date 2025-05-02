class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;  // Even numbers ka frequency track karne ke liye map
        int mostFrequent = -1;  // Default return value agar koi even number nahi mile
        int maxFrequency = 0;  // Maximum frequency store karne ke liye variable

        // Step 1: Even numbers ka frequency count karte hain
        for (int num : nums) {
            if (num % 2 == 0) {  // Agar number even hai
                count[num]++;  // Uska frequency increase karte hain
            }
        }

        // Step 2: Sabse zyada frequent even number find karna
        for (const auto& entry : count) {  // Map ke har entry ko check karte hain
            int num = entry.first;  // Even number
            int freq = entry.second;  // Uska frequency

            // Agar frequency zyada hai ya same frequency pe smallest number chahiye
            if (freq > maxFrequency || (freq == maxFrequency && num < mostFrequent)) {
                mostFrequent = num;  // Update karte hain most frequent ko
                maxFrequency = freq;  // Update karte hain max frequency ko
            }
        }

        return mostFrequent;  // Final result, agar koi even number nahi mila to -1 return hoga
    }
};