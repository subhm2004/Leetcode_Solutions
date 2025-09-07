// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, -1);

//         for (int i = 0; i < n; i++) {
//             for (int j = 1; j < n; j++) {
//                 int next_idx = (i + j) % n;
//                 if (nums[next_idx] > nums[i]) {
//                     ans[i] = nums[next_idx];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> s;

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!s.empty() && nums[idx] > nums[s.top()]) {
                ans[s.top()] = nums[idx];
                s.pop();
            }
            if (i < n)
                s.push(idx);
        }
        return ans;
    }
};
