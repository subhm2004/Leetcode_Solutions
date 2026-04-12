class Solution {
public:
    
    vector<int> isPrime;

    void seive(int n) {
        isPrime.assign(n + 1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int minOperations(vector<int>& nums) {
        
        int maxi = *max_element(nums.begin(), nums.end());

        seive(maxi + 100);

        int min_ops = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (i % 2 == 0) {

                int num = nums[i];

                while (!isPrime[num]) {
                    num++;
                    min_ops++;
                }

            } else {

                int num = nums[i];

                while (isPrime[num]) {
                    num++;
                    min_ops++;
                }
            }
        }

        return min_ops;
    }
};