class Solution {
public:
    vector<bool> sieveEratosthenes(int n) { // TC: O(n log log n)
        vector<bool> isPrime(n + 1, true);   
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i)
            if (isPrime[i])
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
        return isPrime;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        vector<bool> isPrime = sieveEratosthenes(nums.size());   

        for (auto& [_, count] : freq)
            if (isPrime[count])
                return true;

        return false;
    }
};
