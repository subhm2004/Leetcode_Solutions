class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        /*
        important observation

        Kisi bhi turn pe (jab current array ka length m ≥ 2 ho):

        current player chahe to game turant khatam kar sakta hai
        by removing a subarray of length m-1.

        Aur dhyaan do:

        length m-1 ka subarray sirf 2 hi tarah se ho sakta hai:

        [0 … m-2]  -> last element bachta hai
        [1 … m-1]  -> first element bachta hai

        Iska matlab:

        jab bhi game khatam hota hai,
        sirf current array ka first ya last element hi final me bachta hai.
        */
        return max(nums[0], nums[n - 1]);
    }
};