class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int x : nums)
            freq[x]++;

        int dup_count = 0;
        for(auto &p : freq)
            if(p.second > 1) dup_count++;

        if(dup_count == 0) return 0;

        int i = 0;
        int ops = 0;
        int n = nums.size();

        while(i < n && dup_count > 0) {
            ops++;

            int counter = 0;
            while(counter < 3 && i < n) {
                freq[nums[i]]--;

                if(freq[nums[i]] == 1)
                    dup_count--;

                i++;
                counter++;
            }
        }

        return ops;
    }
};
