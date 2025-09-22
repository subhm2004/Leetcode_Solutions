class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>
            count; // har element ki frequency store karne ke liye

        // har number ki frequency count karo
        for (const int num : nums) {
            count[num]++;
        }

        int max_freq = 0;
        // sabse badi frequency nikal lo
        for (const auto& [num, freq] : count)
            max_freq = max(max_freq, freq);

        int max_freq_count = 0;
        // jitne elements ki frequency max ke equal hai unki ginti karo
        for (const auto& [num, freq] : count)
            if (freq == max_freq)
                ++max_freq_count;

        // final answer = max frequency * us frequency wale elements ki ginti
        return max_freq_count * max_freq;
    }
};
