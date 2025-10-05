// class Solution { // TLE Brute force 
// public:
//     int getXORSum(vector<int>& arr1, vector<int>& arr2) {
//         int ans = 0;

//         for (int i = 0; i < arr1.size(); i++) {
//             for (int j = 0; j < arr2.size(); j++) {
//                 ans ^= (arr1[i] & arr2[j]);  
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1 = 0;
        int xor2 = 0;

        // arr1 ke liye
        for (int i = 0; i < arr1.size(); i++) {
            xor1 ^= arr1[i];
        }

        // arr2 ke liye
        for (int j = 0; j < arr2.size(); j++) {
            xor2 ^= arr2[j];
        }

        return xor1 & xor2;
    }
};
