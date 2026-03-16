// Cantor's diagonalization argument (diagonal flip method)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); ++i)
            ans += (nums[i][i] == '0') ? '1' : '0';

        return ans;
    }
};
/*
Agar hum kisi binary string ke collection ko ek 2D matrix ke form me likhein,
toh diagonal elements ko flip karne se ek naya string banta hai jo har existing
string se kam se kam ek position par different hota hai—isiliye woh list me nahi
hoga.
*/
