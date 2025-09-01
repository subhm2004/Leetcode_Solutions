class Solution {
public:
    int sliding_window(string& s, char target, int k) {
        int left = 0;
        int max_len = 0;
        int changes = 0;

        for (int right = 0; right < s.length(); right++) {
            if (s[right] != target)
                changes++;

            while (changes > k) {
                if (s[left] != target)
                    changes--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
    int maxConsecutiveAnswers(string s, int k) {
        int maxi_T = sliding_window(s, 'T', k);
        int maxi_F = sliding_window(s, 'F', k);
        return max(maxi_T, maxi_F);
    }
};

// lets do with binary search

// class Solution {
// public:
//     bool is_possible(string s, char t, int mid, int k) {
//         int n = s.length();
//         int count = 0;

//         for (int i = 0; i < mid; i++) {
//             if (s[i] != t)
//                 count++;
//         }
//         if (count <= k)
//             return true;

//         for (int i = mid; i < n; i++) {
//             if (s[i] != t)
//                 count++;
//             if (s[i - mid] != t)
//                 count--;

//             if (count <= k)
//                 return true;
//         }
//         return false;
//     }

//     int maxConsecutiveAnswers(string s, int k) {
//         //  binary search se kro ab (binary search on answer se hoga like koko
//         //  eating kela)
//         int n = s.length();
//         int left = 1;
//         int right = n;
//         int ans = 0;

//         while (left <= right) {
//             int mid = (left + right) >> 1;

//             if (is_possible(s, 'T', mid, k) || is_possible(s, 'F', mid, k)) {
//                 ans = mid;
//                 left = mid + 1;

//             } else {
//                 right = mid - 1;
//             }
//         }
//         return ans;
//     }
// };