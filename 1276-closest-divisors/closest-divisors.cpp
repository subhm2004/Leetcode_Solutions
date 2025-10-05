class Solution {
public:
    // ye find krega divisors pair ko such that unke beech ka differece kam ho 
    vector<int> find_closest_divisor_pair(int n) { 
        int a = 1, b = n;
        int sqrt_n = sqrt(n); // ek divisor sqrt(n) se chota hota h ek bada hota hai 
        for (int i = 1; i <= sqrt_n; i++) {
            if (n % i == 0) {
                int j = n / i;
                if (abs((long long)i - j) < abs((long long)a - b)){
                    a = i;
                    b = j;
                }
            }
        }
        return {a, b};
    }

    vector<int> closestDivisors(int num) {
        vector<int> pair1 = find_closest_divisor_pair(num + 1);
        vector<int> pair2 = find_closest_divisor_pair(num + 2);
        
        if (abs(pair1[0] - pair1[1]) <= abs(pair2[0] - pair2[1]))
            return pair1;
        return pair2;
    }
};

/*
Explanation (Hinglish):

1. find_closest_divisor_pair(int n):
   - Ye function n ke do divisors find karta hai jinke beech ka absolute difference sabse chhota ho.
   - Sirf sqrt(n) tak check karna kaafi hai kyunki divisors pairs me aate hai: (i, n/i).
   - Loop i = 1 se sqrt(n) tak:
       - Agar i n ko exactly divide karta hai, to paired divisor j = n / i calculate karo.
       - Check karo ki abs(i - j) current minimum difference abs(a - b) se chhota hai ya nahi.
       - Agar chhota hai, to a aur b ko update karo is naye pair se.
   - Last me, {a, b} return karo.

2. closestDivisors(int num):
   - Hume num+1 ya num+2 ke closest divisors me se best pair chahiye.
   - find_closest_divisor_pair ko num+1 aur num+2 par call karo aur do pairs lo.
   - Dono pairs ke differences compare karo aur jo chhota ho us pair ko return karo.

Key points:
- abs() me (long long) cast karne se integer overflow avoid hota hai for large numbers.
- Sirf sqrt(n) tak loop karne se time complexity O(sqrt(n)) ho jati hai instead of O(n).
- Ye method efficient hai aur large inputs ke liye bhi kaam karega.
*/