class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0, evenCount = 1; // evenCount starts as 1 for empty prefix sum
        int prefixSum = 0, totalCount = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                totalCount = (totalCount + oddCount) % MOD;
                evenCount++;
            } else {
                totalCount = (totalCount + evenCount) % MOD;
                oddCount++;
            }
        }

        return totalCount;
    }
};




// class Solution {                 // RECURSIVE SOLUTION HAI KIYA VHI HAI BAS PREFIX SUM SE O(n)ME HOGYA HAI SAB
// public:
//     const int MOD = 1e9 + 7;
//     int countOddSubarrays(vector<int>& arr, int index, int prefixSum,
//                           int oddCount, int evenCount) {
//         if (index == arr.size()) {
//             return 0;
//         }

//         prefixSum += arr[index];

//         int count;
//         if (prefixSum % 2 == 0) {
//             count = oddCount;
//             evenCount++;
//         } else {
//             count = evenCount;
//             oddCount++;
//         }

//         return (count + countOddSubarrays(arr, index + 1, prefixSum, oddCount,
//                                           evenCount)) %
//                MOD;
//     }

//     int numOfSubarrays(vector<int>& arr) {
//         return countOddSubarrays(arr, 0, 0, 0, 1); // evenCount starts as 1
//     }
// };

// class Solution {              // TLE AAGYA O(n^2) ka solution hai
// public:
//     const int MOD = 1e9 + 7;
//     // Recursive function to count subarrays with odd sum
//     int countOddSubarrays(vector<int>& arr, int index, int sum) {
//         if (index == arr.size()) {
//             return 0;
//         }

//         sum += arr[index];
//         int count = (sum % 2 != 0) ? 1 : 0;

//         return (count + countOddSubarrays(arr, index + 1, sum)) % MOD;
//     }

//     int numOfSubarrays(vector<int>& arr) {
//         int total_count = 0;

//         for (int i = 0; i < arr.size(); i++) {
//             total_count = (total_count + countOddSubarrays(arr, i, 0)) % MOD;
//         }

//         return total_count;
//     }
// };