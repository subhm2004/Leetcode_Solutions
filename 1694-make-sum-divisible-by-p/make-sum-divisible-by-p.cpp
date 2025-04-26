#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> remainderIndex; // remainder -> last index
        
        int totalRemainder = 0; // poore array ka sum ka remainder
        
        // Step 1: Poore array ka total remainder nikaal rahe hain
        for (int num : nums) {
            totalRemainder = (totalRemainder + num) % p;
        }
        
        // Step 2: Agar total remainder 0 hai, matlab poora array p se divisible hai
        if (totalRemainder == 0) {
            return 0;
        }
        
        remainderIndex[0] = -1; // Shuru me remainder 0 ke liye index -1 set kar rahe hain
        
        int ans = n; // Answer ko initially maximum length set kar rahe hain
        int currentRemainder = 0; // ab tak ka prefix sum remainder
        
        // Step 3: Traverse karte hain array ko
        for (int i = 0; i < n; i++) {
            // Current prefix sum remainder update karte hain
            currentRemainder = (currentRemainder + nums[i]) % p;
            
            // Required remainder calculate karte hain
            int required = (currentRemainder - totalRemainder + p) % p;
            
            // Check karte hain ki required remainder kab mila tha
            if (remainderIndex.find(required) != remainderIndex.end()) {
                // Agar mila, to minimum length update karte hain
                ans = min(ans, i - remainderIndex[required]);
            }
            
            // Current remainder ka last index update karte hain
            remainderIndex[currentRemainder] = i;
        }
        
        // Step 4: Final answer return karte hain
        return ans == n ? -1 : ans;
    }
};
