class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    const int n = nums.size();
    const int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> minPrimeFactor = sieve(maxVal + 1);
    vector<int> primeScores = getPrimeScores(nums, minPrimeFactor);
    
    vector<int> left(n, -1), right(n, n);
    stack<int> s;

    // Finding left boundaries
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && primeScores[s.top()] <= primeScores[i]) {
        left[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }

    s = stack<int>(); // Reset stack

    // Finding right boundaries
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && primeScores[s.top()] < primeScores[i]) {
        right[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }

    vector<pair<int, int>> sortedNums;
    for (int i = 0; i < n; ++i)
      sortedNums.emplace_back(nums[i], i);

    sort(sortedNums.rbegin(), sortedNums.rend());

    long ans = 1;
    for (const auto& [num, i] : sortedNums) {
      long rangeCount = (long)(i - left[i]) * (right[i] - i);
      long useCount = min(rangeCount, (long)k);
      k -= useCount;
      ans = ans * modPow(num, useCount) % MOD;
      if (k == 0) break;
    }

    return ans;
  }

 private:
  static constexpr int MOD = 1'000'000'007;

  long modPow(long base, long exp) {
    long res = 1;
    while (exp) {
      if (exp % 2) res = res * base % MOD;
      base = base * base % MOD;
      exp /= 2;
    }
    return res;
  }

  vector<int> sieve(int n) {
    vector<int> minPrime(n, 0);
    iota(minPrime.begin(), minPrime.end(), 0);
    for (int i = 2; i * i < n; ++i)
      if (minPrime[i] == i)  // Prime number
        for (int j = i * i; j < n; j += i)
          if (minPrime[j] == j)
            minPrime[j] = i;
    return minPrime;
  }

  vector<int> getPrimeScores(const vector<int>& nums, const vector<int>& minPrime) {
    vector<int> scores;
    for (int num : nums)
      scores.push_back(getPrimeScore(num, minPrime));
    return scores;
  }

  int getPrimeScore(int num, const vector<int>& minPrime) {
    unordered_set<int> primes;
    while (num > 1) {
      primes.insert(minPrime[num]);
      num /= minPrime[num];
    }
    return primes.size();
  }
};
