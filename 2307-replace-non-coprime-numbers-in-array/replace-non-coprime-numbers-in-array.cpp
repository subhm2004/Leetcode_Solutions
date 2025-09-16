class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans; //or you can use a stack

        //Processing left to right
        for(int num : nums) {

            while(!ans.empty()) {
                int prev = ans.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if(GCD == 1) { // co-primes ki condition check hogu yha 
                    break;
                }

                ans.pop_back();
                int LCM = prev / GCD * curr;

                num = LCM; //merged number
            }
            ans.push_back(num); //merged num put back to ans
        }
        return ans;
    }
};