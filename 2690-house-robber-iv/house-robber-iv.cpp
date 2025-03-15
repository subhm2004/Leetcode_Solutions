class Solution {
public:
    // Ye function count karega ki given 'capacity' tak kitne ghar loot sakte hain
    int count_house_helper(vector<int>& nums, int capacity) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= capacity) {
                ++count;
                i++; // Agla ghar skip karna hai kyunki adjacent ghar loot nahi sakte
            }
        }
        return count;
    }

    int minCapability(vector<int>& nums, int k) {
        // int left = 1, right = 1e5;
        
        // Min aur max element dhoondh rahe hain jo binary search ka range banayega
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left <= right) {
            int mid = (left + right) >> 1; // Mid value nikal rahe hain
            if (count_house_helper(nums, mid) >= k)
                right = mid-1; // Agar itne ghar loot sakte hain toh capacity aur kam karo
            else
                left = mid + 1; // Agar nahi loot sakte toh capacity badhao
        }
        return left; // Minimum capacity return karenge
    }
};
