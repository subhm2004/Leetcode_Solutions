class Solution {
public:
     void helper(unordered_map<int, int>& count, vector<int>& nums) {
        unordered_map<int, bool> seen;  // Track karne ke liye ki number pehle se is array me count ho chuka hai ya nahi
        for (int num : nums) {
            if (!seen[num]) {  // Agar ye number pehli baar aa raha hai is array me
                ++count[num];   // Overall count badhayein
                seen[num] = true;  // Is array me is number ko mark kar do
            }
        }
    }

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> count;  // Har number ka unique array me aane ka count store karne ke liye
        vector<int> ans;

        // Har array ke unique numbers ka count badhane ke liye
        helper(count, nums1);
        helper(count, nums2);
        helper(count, nums3);

        // Jo numbers kam se kam do arrays me aaye hain, unhe answer me daalo
        for (auto& [num, freq] : count) {
            if (freq >= 2) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
