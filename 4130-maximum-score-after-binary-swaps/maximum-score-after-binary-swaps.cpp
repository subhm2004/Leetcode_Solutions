class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        priority_queue<int> pq;   // max-heap 
        long long score = 0;

        for(int i = 0; i < n; i++) {
            pq.push(nums[i]);     // index i tak jo values reachable hain, unhe heap me daal do

            if(s[i] == '1') {
                score += pq.top(); // is '1' ke liye sabse badi available value use kar li
                pq.pop();          // ek '1' place ho gaya to hata de
            }
        }

        return score;
    }
};
/*
Jab index i par '1' milta hai,
tab heap me sirf wahi values hoti hain jo reachable hain (0…i)
*/