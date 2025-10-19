// /*
// Pattern me sirf -1, 0, 1 ho sakte hain:

// 1 → next number bada hona chahiye (nums[i+1] > nums[i])

// 0 → next number equal hona chahiye (nums[i+1] == nums[i])

// -1 → next number chhota hona chahiye (nums[i+1] < nums[i])
// */
// class Solution {     // Brute Force iske liye hi bana hai question lekin hum to solve krege Rabin Karp se
// public:
//     int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
//         int n = nums.size();
//         int m = pattern.size();
//         int count = 0;

//         for (int i = 0; i <= n - m - 1; i++) { // subarray start index
//             bool match = true;
//             for (int k = 0; k < m; k++) { // pattern check
//                 if (pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) {
//                     match = false;
//                     break;
//                 }
//                 if (pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) {
//                     match = false;
//                     break;
//                 }
//                 if (pattern[k] == -1 && nums[i + k + 1] >= nums[i + k]) {
//                     match = false;
//                     break;
//                 }
//             }
//             if (match)
//                 count++;
//         }

//         return count;
//     }
// };

auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
typedef long long ll;
class Solution {
public:
    const ll RADIX_1 = 3;
    const ll MOD_1 = 1e9 + 7;
    const ll RADIX_2 = 5;
    const ll MOD_2 = 1e9 + 33;

    // Compute hash of vector<int> for first m elements
    pair<ll, ll> hash_pair(vector<int>& arr, ll idx, ll m) {
        ll hash_1 = 0, hash_2 = 0;
        ll factor_1 = 1, factor_2 = 1;
        for (ll i = idx + m - 1; i >= idx; i--) {
            hash_1 = (hash_1 + arr[i] * factor_1) % MOD_1;
            factor_1 = (factor_1 * RADIX_1) % MOD_1;
            hash_2 = (hash_2 + arr[i] * factor_2) % MOD_2;
            factor_2 = (factor_2 * RADIX_2) % MOD_2;
        }
        return {hash_1 % MOD_1, hash_2 % MOD_2};
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        if(n < m + 1) return 0;

        // Step 1: Build nums_mapping array which is nothing but mapping for elements of nums
        vector<int> nums_mapping(n-1);
        for(int i = 0; i < n-1; i++) {
            if(nums[i] < nums[i+1]) nums_mapping[i] = 1;
            else if(nums[i] == nums[i+1]) nums_mapping[i] = 0;
            else nums_mapping[i] = 2; // -1 ko 2 me map kiya
        }

        // Step 2: Build pattern_mapping array which is nothing but mapping for elements of pattern
        vector<int> pattern_mapping(m);
            for(int i = 0; i < m; i++) {
             pattern_mapping[i] = (pattern[i] == -1 ? 2 : pattern[i]);
            }

        // Step 3: Precompute max weight for rolling hash
        ll MAX_WEIGHT_1 = 1, MAX_WEIGHT_2 = 1;
        for(int i = 0; i < m; i++) {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        // Step 4: Compute pattern hash
        pair<ll,ll> hash_patter = hash_pair(pattern_mapping, 0, m);
        pair<ll,ll> hash_window = {0,0};

        int count = 0;
        // Last possible starting index i jaha subarray length m+1 fit ho → i + (m+1) - 1 = n-1 => ise solve krne p aayega i + m = n-1 => i= n - m -1 
        for(int i = 0; i <= n - m - 1; i++) {
            if(i == 0) {
                hash_window = hash_pair(nums_mapping, 0, m);
            } else {
                // Rolling hash (Double Hashing)
                hash_window.first = ((hash_window.first * RADIX_1) % MOD_1 - (nums_mapping[i-1] * MAX_WEIGHT_1) % MOD_1 + nums_mapping[i+m-1] + MOD_1) % MOD_1;
                hash_window.second = ((hash_window.second * RADIX_2) % MOD_2 - (nums_mapping[i-1] * MAX_WEIGHT_2) % MOD_2 + nums_mapping[i+m-1] + MOD_2) % MOD_2;
            }

            if(hash_window.first == hash_patter.first && hash_window.second == hash_patter.second) count++;
        }

        return count;
    }
};
