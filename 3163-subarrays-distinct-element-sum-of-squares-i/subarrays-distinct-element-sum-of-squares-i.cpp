class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();  // nums array ka size
        int ans = 0;  // Result store karne ke liye
        unordered_map<int, int> freq; // Frequency map banaya hai jo current window ke elements ko store karega
        
        // Sabhi subarrays ke liye
        for (int i = 0; i < n; i++) {
            int distinct_Count = 0;  // Har subarray ke liye distinct count initialize
            freq.clear();  // Har naye subarray ke start par frequency map ko clear karte hain
            
            // Subarray ke elements ko iterate karte hain
            for (int j = i; j < n; j++) {
                // Agar current element pehli baar aata hai, to distinct count ko increment karo
                if (freq[nums[j]] == 0) {
                    distinct_Count++;  // Naya distinct element mila
                }
                freq[nums[j]]++;  // Element ki frequency update karo
                
                // Distinct count ka square ans me add karo
                ans += distinct_Count * distinct_Count;
            }
        }
        
        return ans;  
    }
};
