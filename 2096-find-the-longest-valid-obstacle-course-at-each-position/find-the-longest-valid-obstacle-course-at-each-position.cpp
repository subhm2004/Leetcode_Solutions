// class Solution {
// public:
//     vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
//         int n = obstacles.size();
//         vector<int> dp(n, 1); // har index pe minimum length 1 hai
//         vector<int> ans(n, 1); 

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 // non-decreasing condition
//                 if (obstacles[j] <= obstacles[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             ans[i] = dp[i]; // har index pe LIS ki length ending at i
//         }
//         return ans;
//     }
// };
class Solution {
public:

    // Ye function wo position return karta hai jahan par
    // current obstacle (target) ko lis me daalna chahiye
    // Aisi position jahan pehle element usse chhota ya barabar ho
    int findPosition(vector<int>& lis, int target) {
        int low = 0, high = lis.size();

        while (low < high) {
            int mid = (low + high) / 2;

            // Agar mid waala element <= target hai to
            // iska matlab target right me jayega
            if (lis[mid] <= target) {
                low = mid + 1;
            } else {
                // Agar bada mila, to search left me
                high = mid;
            }
        }

        // yahi wo position hai jahan target ko insert/update karna chahiye
        return low;
    }
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;  // Final answer store karega
        vector<int> lis;  // Ye non-decreasing subsequence ka tail store karta hai

        for (int i = 0; i < obstacles.size(); ++i) {
            int h = obstacles[i];  // Current obstacle height

            // findPosition se wo index milega jahan h ko daal sakte ho
            int index = findPosition(lis, h);

            // Agar h sabse bada hai to lis me add kar do
            if (index == lis.size()) {
                lis.push_back(h);
            } else {
                // Warna us position par update kar do (smaller height maintain rakhne ke liye)
                lis[index] = h;
            }

            // index + 1 is the length of longest obstacle course ending at i
            ans.push_back(index + 1);
        }

        return ans;
    }
};
