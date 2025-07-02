// class Solution {     // using unordered_map
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int, int> counter;
//         for (int num : nums) {
//             counter[num]++;
//         }
        
//         vector<int> ans;
//         int n = nums.size();
//         for (auto& pair : counter) {
//             if (pair.second > n / 3) {
//                 ans.push_back(pair.first);
//             }
//         }
//         return ans;
//     }
// };



// class Solution {        // using sorting
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> ans;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < n; ) {
//             int j = i + 1;
//             while (j < n && nums[j] == nums[i]) j++;
            
//             if (j - i > n / 3) {
//                 ans.push_back(nums[i]);
//             }

//             i = j; // Move to the next distinct element
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 1; // initialize to different values
        int count1 = 0, count2 = 0;

        // First pass: find potential candidates
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: verify candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> ans;
        int n = nums.size();
        if (count1 > n / 3) ans.push_back(candidate1);
        if (count2 > n / 3) ans.push_back(candidate2);

        return ans;
    }
};
