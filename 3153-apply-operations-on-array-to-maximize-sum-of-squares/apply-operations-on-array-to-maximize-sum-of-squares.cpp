class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(32,0);

        for(int i=0;i<n;i++){
            for(int j=31;j>=0;j--){
                int num = nums[i];
                if(num & (1 << j)){
                    freq[j]++;
                }
            }
        }

        int ans = 0;
        int mod = 1e9+7;

        while(k--){
            int p = 0;
            int num = 0;
            for(int i=0;i<=31;i++){
                if(freq[i] > 0){
                    freq[i]--;
                    num += pow(2,p);
                }
                p++;
            }
            int toAdd = ((long long)num*num)%mod;
            ans = (ans + toAdd) % mod;
        }

        return ans;
    }
};