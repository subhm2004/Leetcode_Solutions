class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int num_operations) {
        int max_val = *max_element(begin(nums), end(nums)) + k;
        map<int, int> diff; //map     
        unordered_map<int, int> freq;

        //O(nlogn)
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, max_val);

            diff[l]++;
            diff[r+1]--;

            diff[nums[i]] += 0; //Focus
        }


        int ans = 1;
        int cumm_sum = 0;
        //O(n)
        for(auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;
            it->second += cumm_sum;

            int targetFreq     = freq[target];
            int nedd_comversion = it->second - targetFreq;

            int max_possible_freq = min(nedd_comversion, num_operations);

            ans = max(ans, targetFreq + max_possible_freq);

            cumm_sum = it->second;
        }

        return ans;
    }
};