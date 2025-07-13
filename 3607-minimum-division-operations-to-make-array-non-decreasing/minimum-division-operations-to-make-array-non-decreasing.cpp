class Solution {   
public:
    // find greatest proper divisor ( ye hi de rha h tle isme kyoki sab ke upar jake check krra hai)
    int GPD_1(int x) { 
        for (int d = x / 2; d >= 1; --d) {
            if (x % d == 0) return d;
        }
        return 1; // for primes or 1
    }

    /*
    Agar x = a * b hai
    Aur a <= b hai
    Toh iska mltb hai ki jo :

    a = smallest factor

    b = greatest proper divisor (GPD)

    Toh GPD(x) = x / smallest prime factor

    */

    int GPD_2(int x) {  // ye aagya fast method 
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) return x / d;
    }
    return 1; // agar x prime hai, toh uska GPD 1 hota hai
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;

        for (int i = n - 2; i >= 0; --i) {
            int curr = nums[i];

            while (curr > nums[i + 1]) {
                int gpd = GPD_2(curr);

                // Agar GPD 1 ho gaya aur abhi bhi bada hai to not possible
                if (gpd == 1) return -1;
                curr /= gpd;
                ops++;
            }

            nums[i] = curr;
        }

        return ops;
    }
};
