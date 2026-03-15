class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        // same array check 
        unordered_map<int,int> freq;

        for(int x : nums1) freq[x]++;
        for(int x : nums2) freq[x]++;

        for(auto &[num, count] : freq){
            if(count % 2) return -1;
        }

        // alag alag array me check 
        unordered_map<int,int> diff;

        for(int x : nums1) diff[x]++;
        for(int x : nums2) diff[x]--;

        long long mismatch = 0;

        for(auto &[num, count] : diff){
            mismatch += abs(count);
        }

        return mismatch / 4;
    }
};