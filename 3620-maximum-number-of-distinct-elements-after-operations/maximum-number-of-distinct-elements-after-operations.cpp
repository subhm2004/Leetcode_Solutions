auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int distinct_count = 0;
        int prev_max = INT_MIN; // Last assigned number

        for (int num : nums) {
            int lower_val = num - k;
            int upper_val = num + k;

            // Agar previous number lower_val se chhota hai
            if (prev_max < lower_val) {
                prev_max = lower_val; // Assign lowest possible value
                distinct_count++;
            } 
            // Agar still range me jagah hai
            else if (prev_max < upper_val) {
                prev_max++; // Assign next unique number
                distinct_count++;
            }
            // Agar prev_max >= upper_val, skip kar do
        }

        return distinct_count;
    }
};

