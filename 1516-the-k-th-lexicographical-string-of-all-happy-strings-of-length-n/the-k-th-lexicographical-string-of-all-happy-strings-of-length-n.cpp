class Solution {
 public:
   void backtrack(int n, int k, string current, string& ans, int& count) {
    // Agar current string ki length n tak pahunch gayi, to check karna hai ki ye k-th string hai ya nahi
    if (current.length() == n) {
      if (++count == k) {  // Agar k-th valid string mil gayi to ans store kar lo
        ans = current;
      }
      return;
    }

    // 'a', 'b', 'c' characters ko try karna hai
    for (char ch : {'a', 'b', 'c'}) {
      // Consecutive same characters nahi hone chahiye
      if (current.empty() || current.back() != ch) {
        backtrack(n, k, current + ch, ans, count); // Next character add karke recursion call kar rahe hain
        if (!ans.empty())  // Agar k-th string mil chuki hai to aage recursion call nahi karna
          return;
      }
    }
  }

  string getHappyString(int n, int k) {
    string ans;
    int count = 0;
    backtrack(n, k, "", ans, count);  // Recursion start karna hai empty string se
    return ans;  // Agar k-th string mil gayi to return hogi, nahi mili to empty string return hogi
  }
};
