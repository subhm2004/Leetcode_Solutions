class Solution {
public:
    unordered_map<string, int> dp;

    int countBeautifulNumbers(int index, int state, int hasNonZero, string &num, long long product, int digitSum) {
        if (index == num.size()) {  
            if (product == 0) return 1;  
            return (digitSum != 0 && product % digitSum == 0) ? 1 : 0;  
        }

        string key = to_string(index) + "," + to_string(state) + "," + to_string(hasNonZero) + "," + to_string(product) + "," + to_string(digitSum);
        if (dp.find(key) != dp.end()) return dp[key];

        int currentDigit = num[index] - '0';
        int totalWays = 0;

        if (hasNonZero == 0) {  
            if (state == 0) {  
                for (int i = 0; i < currentDigit; ++i) {  
                    totalWays += countBeautifulNumbers(index + 1, 1, i > 0, num, (i == 0) ? 1 : product * i, digitSum + i);
                }  
                totalWays += countBeautifulNumbers(index + 1, 0, currentDigit > 0, num, (currentDigit == 0) ? 1 : product * currentDigit, digitSum + currentDigit);
            } 
            else {  
                for (int i = 0; i < 10; ++i) {  
                    totalWays += countBeautifulNumbers(index + 1, 1, i > 0, num, (i == 0) ? 1 : product * i, digitSum + i);
                }  
            }
            return dp[key] = totalWays;
        }

        if (state == 0) {
            for (int i = 0; i < currentDigit; ++i) {
                totalWays += countBeautifulNumbers(index + 1, 1, 1, num, product * i, digitSum + i);
            }
            totalWays += countBeautifulNumbers(index + 1, 0, 1, num, product * currentDigit, digitSum + currentDigit);
        } 
        else {
            for (int i = 0; i < 10; ++i) {
                totalWays += countBeautifulNumbers(index + 1, 1, 1, num, product * i, digitSum + i);
            }
        }

        return dp[key] = totalWays;
    }

    int beautifulNumbers(int l, int r) {
        dp.clear(); // Clear the memoization table before each call
        string left = to_string(l - 1);
        string right = to_string(r);

        int countL = countBeautifulNumbers(0, 0, 0, left, 1, 0); 

        dp.clear(); // Clear before second call to avoid interference
        int countR = countBeautifulNumbers(0, 0, 0, right, 1, 0); 
        
        return countR - countL;
    }
};
