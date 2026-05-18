class Solution {
public:

    const int MOD = 1e9 + 7;

    int numberOfGoodPartitions(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> last_idx; // number -> last idx of occurence of number 

        for(int i = 0; i < n; i++) {
            last_idx[nums[i]] = i;
        }

        int partitions = 0;

        int i = 0;
        int j = -1;

        while(i < n) {

            // naya partition start
            if(i > j) {
                partitions++;
            }

            j = max(j, last_idx[nums[i]]);

            i++;
        }

        long long ans = 1;

        // M partitions ke liye M-1 cuts lagte hai or har cut pr ye hota h mari ya na maro to total ho gya hai 2^M-1
        for(int i = 1; i < partitions; i++) {
            ans = (ans * 2) % MOD;
        }

        return ans;
    }
};