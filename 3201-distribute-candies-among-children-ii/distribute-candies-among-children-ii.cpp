class Solution {
public:
    long nCr(int n, int r) {
        long ans = 1;
        for (int i = 1; i <= r; ++i)
            ans = ans * (n - i + 1) / i;
        return ans;
    }

    long ways(int n) { 
        if (n < 0)
            return 0;
        return nCr(n + 3 - 1, 3 - 1); // Using stars and bars method (Beggar's coin method )
    }

    long long ways2(int n) { // n+2 C 2 hai jo ki (n+2)*(n+1)/2 likhi ja skti hai 
        if (n < 0) return 0;
        return 1LL * (n + 2) * (n + 1) / 2;
    }

  long long distributeCandies(int n, int limit) {
    int limit_Plus_One = limit + 1;
    long one_Child_Exceeds_Limit = ways2(n - limit_Plus_One);
    long two_Children_Exceed_Limit = ways2(n - 2 * limit_Plus_One);
    long three_Children_Exceed_Limit = ways2(n - 3 * limit_Plus_One);
    
    // Principle of Inclusion-Exclusion  
    return ways2(n) - 3 * one_Child_Exceeds_Limit + 3 * two_Children_Exceed_Limit -
           three_Children_Exceed_Limit;
  }
};



// class Solution {
// public:
//     long long distributeCandies(int n, int limit) {
//         int ways = 0;

//         for (int x1 = 0; x1 <= min(n, limit); ++x1) {
//             for (int x2 = 0; x2 <= min(n - x1, limit); ++x2) {
//                 int x3 = n - x1 - x2;
//                 if (x3 >= 0 && x3 <= limit) {
//                     ++ways;
//                 }
//             }
//         }

//         return ways;
//     }
// };