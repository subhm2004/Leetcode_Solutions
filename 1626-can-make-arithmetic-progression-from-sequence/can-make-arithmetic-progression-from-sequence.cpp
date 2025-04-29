// class Solution {
// public:
//     bool canMakeArithmeticProgression(vector<int>& arr) {
//         sort(arr.begin(), arr.end());  

//         int diff = arr[1] - arr[0]; // Common difference 

//         for (int i = 2; i < arr.size(); i++) {
//             if (arr[i] - arr[i - 1] != diff) {
//                 return false; 
//             }
//         }

//         return true;
//     }
// };
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        // If there's only one element, it's trivially an arithmetic progression
        if (n == 1) {
            return true;
        }

        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        // Check if difference between max and min is divisible by (n-1)
        if ((maxVal - minVal) % (n - 1) != 0) {
            return false;
        }

        int diff = (maxVal - minVal) / (n - 1); // Common difference
        if (diff == 0) return true;
        unordered_set<int> seen;

        for (int num : arr) {
            // Check if the number is out of bounds or already seen
            if ((num - minVal) % diff != 0 || seen.count(num)) {
                return false;
            }
            seen.insert(num);
        }

        return true;
    }
};
