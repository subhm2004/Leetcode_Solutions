class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        // freq[x] = current window [left ... right]
        // mein x kitni baar present hai
        unordered_map<int, int> freq;

        int ans = 0;

        // right = window ka right end
        // left = window ka left end
        // most = window mein kisi bhi element ki maximum frequency
        int left = 0;
        int most = 0;

        for (int right = 0; right < n; right++) {

            // Current element ko window mein add karo
            freq[nums[right]]++;

            // Check karo ki ab maximum frequency kya hai
            most = max(most, freq[nums[right]]);

            /*
                Current window:

                    [left ........ right]

                Total elements: right - left + 1

                Humein sirf 'most' same elements bachane hain.

                Baaki elements delete karne padenge:

                    deletions = total elements - most

                    = (right - left + 1) - most

                Agar deletions > k hain,
                toh window invalid hai.
            */

            while ((right - left + 1) - most > k) {

                // Left wala element window se remove karo
                freq[nums[left]]--;

                left++;
            }

            /*
                Ab window valid hai.

                Hum is window mein maximum frequency
                wale element ke 'most' copies rakh sakte hain.

                Isliye answer = most.
            */
            ans = max(ans, most);
        }

        return ans;
    }
};