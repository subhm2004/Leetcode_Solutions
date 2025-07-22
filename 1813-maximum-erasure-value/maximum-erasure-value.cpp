class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;  // unique elements ka track rakhne ke liye
        int start = 0 ;
        int  curr_sum = 0;
        int  maxi = 0;

        for (int end = 0; end < nums.size(); ++end) {
            // agar duplicate mila, to window ko left se chhota karo
            while (seen.count(nums[end])) {
                seen.erase(nums[start]);        // start wala element remove karo
                curr_sum -= nums[start];         // uska sum bhi kam karo
                start++;                        // aur window aage badhao
            }

            seen.insert(nums[end]);             // current element ko set me daalo
            curr_sum += nums[end];               // aur sum me add karo
            maxi = max(maxi, curr_sum);  // max score update karte hai 
        }

        return maxi;
    }
};
