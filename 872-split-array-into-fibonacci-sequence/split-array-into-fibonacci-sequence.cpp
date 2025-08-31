class Solution {
public:
    bool backtrack(string &num, vector<int> &arr, int idx) {
        if (idx == num.size()) {
            return arr.size() >= 3; // valid arr
        }

        long long curr_num = 0;
        for (int i = idx; i < num.size(); ++i) {
            // leading zero check
            if (i > idx && num[idx] == '0') break;

            curr_num = curr_num * 10 + (num[i] - '0');
            if (curr_num > INT_MAX) break; // 32-bit signed integer limit

            int size = arr.size();
            if (size >= 2) {
                
                long long sum_of_last_two = (long long)arr[size - 1] + arr[size - 2];

                if (curr_num < sum_of_last_two) continue; // need bigger number
                if (curr_num > sum_of_last_two) break;    // cannot match, stop
            }

            arr.push_back(curr_num);

            if (backtrack(num, arr, i + 1)) {
                return true;
            }

            arr.pop_back(); // backtrack
        }

        return false;
    }
    
    vector<int> splitIntoFibonacci(string num) {
        vector<int> arr;
        if (backtrack(num, arr, 0)) {
            return arr;
        }
        return {};  
    }
};
