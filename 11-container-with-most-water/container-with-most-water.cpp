class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = INT_MIN;  // Sabse zyada paani store karne wali area ka size track karne ke liye

        int left = 0, right = height.size() - 1;  // Do pointer – ek start se (left) aur ek end se (right)

        while (left < right) {
            // Dono pointers ke beech ki minimum height nikal ke current area calculate karte hain
            int h = min(height[left], height[right]);

            // Max area update karte hain agar current area zyada ho
            max_water = max(max_water, h * (right - left));

            // Jis side ki height chhoti hai us pointer ko aage badhate hain
            // Kyunki chhoti height se area limited hoti hai, toh usse badhane ki koshish karte hain
            if (height[left] < height[right])
                left++;  // Left height chhoti hai toh left pointer aage badhao
            else
                right--;  // Right height chhoti ya barabar hai toh right pointer peeche le jao
        }

        return max_water;  // Sabse zyada paani wala area return karo
    }
};
