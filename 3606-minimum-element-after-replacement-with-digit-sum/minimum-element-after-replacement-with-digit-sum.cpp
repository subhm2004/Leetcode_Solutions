class Solution {
public:
    int sum_Of_Digits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int mini = INT_MAX;  
        
        for (auto& num : nums) {
            int digitSum = sum_Of_Digits(num);  
            mini = min(mini, digitSum);   
        }
        
        return mini;  
    }
};
