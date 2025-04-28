// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         int n = arr.size();
//         int threshold = n / 4;

    

//         // Check for any element that appears more than n/4 times
//         for (int i = 0; i < n - threshold; ++i) {
//             if (arr[i] == arr[i + threshold]) {
//                 return arr[i];
//             }
//         }
        
//         // If no such element is found, return -1 or a default value (though this case should not occur)
//         return -1;
//     }
// };
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int threshold = n / 4;
        unordered_map<int, int> freqMap;

        // Count the frequency of each element
        for (int num : arr) {
            freqMap[num]++;
        }

        // Check if any element appears more than n/4 times
        for (const auto& entry : freqMap) {
            if (entry.second > threshold) {
                return entry.first;
            }
        }

        // If no such element is found, return -1
        return -1;
    }
};
