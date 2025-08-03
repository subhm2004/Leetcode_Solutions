class Solution {
public:
    long long count_valid_substrings(string s, vector<int>& arr, int t) {
        int n = s.length();
        string modified = s;
        for (int i = 0; i <= t; i++) {
            modified[arr[i]] = '*';
        }

        long long total_substrings = (long long)n * (n + 1) / 2;
        long long sub_string_without_star = 0;
        int consecutive_non_star = 0;

        for (int i = 0; i < n; i++) {
            if (modified[i] != '*') {
                consecutive_non_star++;
            } else {
                sub_string_without_star += (long long)consecutive_non_star * (consecutive_non_star + 1) / 2;
                consecutive_non_star = 0;
            }
        }

        sub_string_without_star += (long long)consecutive_non_star * (consecutive_non_star + 1) / 2;
        long long count = total_substrings - sub_string_without_star;
        return count;
    }

    int minTime(string s, vector<int>& order, int k) {
        int n = s.length();
        vector<int> arr = order;  
        int left = 0, right = n - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long valid_count = count_valid_substrings(s, arr, mid);

            if (valid_count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
