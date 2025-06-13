// class Solution {     // TLE  1022/1582
// public:
//     int min_Max_Diff = INT_MAX;

//     void backtrack(vector<int>& nums, vector<bool>& visited, int p, int index, int formed_Pairs, int currMax) {
//         if (formed_Pairs == p) {
//             min_Max_Diff = min(min_Max_Diff, currMax);
//             return;
//         }

//         for (int i = index; i < nums.size(); ++i) {
//             if (visited[i]) continue;
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if (visited[j]) continue;

//                 visited[i] = visited[j] = true;

//                 int diff = abs(nums[i] - nums[j]);
//                 backtrack(nums, visited, p, i + 1, formed_Pairs + 1, max(currMax, diff));

//                 visited[i] = visited[j] = false;
//             }
//         }
//     }

//     int minimizeMax(vector<int>& nums, int p) {
//         int n = nums.size();
//         vector<bool> visited(n, false);
//         min_Max_Diff = INT_MAX;

//         backtrack(nums, visited, p, 0, 0, 0);
//         return min_Max_Diff;
//     }
// };

class Solution {
public:
    bool can_Form_Pairs(vector<int>& nums, int max_Diff, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] - nums[i-1] <= max_Diff) {
                count++;
                i += 2; // Use both indices
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front(); // max possible diff

        while (low < high) {
            int mid = (low + high) >> 1;
            if (can_Form_Pairs(nums, mid, p)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
