class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Agar pehle se sab equal hain -> 0 operations
        bool allEqual = true;
        for (int x : nums) {
            if (x != nums[0]) { allEqual = false; break; }
        }
        if (allEqual) return 0;

        // Warna hamesha 1 operation kaafi hai:
        // poora array ek baar choose karo -> sab global AND ban jayenge
        return 1;
    }
};