class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long result = 0;           // total “good” subarrays ka count
        long long pairCount = 0;        // current window mein equal pairs ki sankhya
        unordered_map<int,int> freq;    // har number ki frequency window mein
        int left = 0;                   // sliding window ka left boundary

        // window ko right taraf se ek-ek karke expand karte hain
        for (int right = 0; right < nums.size(); ++right) {
            // jab nums[right] add karte hain, 
            // agar wo pehle se f baar hua hai, toh f naye pairs banenge
            pairCount += freq[nums[right]];
            freq[nums[right]]++;

            // jab tak pairCount >= k hai, window ko shrink karo
            while (pairCount >= k) {
                // nums[left] remove karne se jo f pairs ghatenge,
                // wo exactly current freq[nums[left]] - 1 ke barabar honge
                freq[nums[left]]--;
                pairCount -= freq[nums[left]];
                left++;
            }

            // ab pairCount < k hai, 
            // toh jitne bhi subarray nums[0..right], nums[1..right], ..., nums[left-1..right]
            // sab “good” hain, unki sankhya = left
            result += left;
        }

        return result;
    }
};
