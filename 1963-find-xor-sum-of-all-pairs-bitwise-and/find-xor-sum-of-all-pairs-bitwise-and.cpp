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
        // Step 1: Brute force definition
        // ans = ⨁(a ∈ arr1) ⨁(b ∈ arr2) (a & b)

        // Step 2: Fix ek b
        // Inner XOR: ⨁(a ∈ arr1) (a & b)

        // Step 3: Distributive property of AND w.r.t XOR
        // (a1&b) ⊕ (a2&b) ⊕ ... ⊕ (an&b) = (a1⊕a2⊕...⊕an) & b
        // Yani inner XOR collapse ho gaya:
        // ⨁(a ∈ arr1)(a & b) = (⨁(a ∈ arr1) a) & b

        // Step 4: Ab outer XOR lo sabhi b ke liye
        // ans = ⨁(b ∈ arr2)[(⨁(a ∈ arr1) a) & b]
        // Isme (⨁(a ∈ arr1) a) ek constant hai => maan lo X1
        // ans = ⨁(b ∈ arr2)(X1 & b)

        // Step 5: Fir se distributive property lagao
        // (X1&b1) ⊕ (X1&b2) ⊕ ... ⊕ (X1&bm) = X1 & (b1⊕b2⊕...⊕bm)
        // Yani ans = (⨁arr1) & (⨁arr2)

        // Final Formula:
        // ans = XOR(arr1) & XOR(arr2)

        int xor1 = 0, xor2 = 0;
        for (int a : arr1) xor1 ^= a; // XOR of arr1
        for (int b : arr2) xor2 ^= b; // XOR of arr2

        return xor1 & xor2;  
    }
};
