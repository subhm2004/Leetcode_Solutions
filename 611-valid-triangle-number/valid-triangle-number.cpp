// class Solution {
// public:
//     int triangleNumber(vector<int>& arr) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end()); // Step 1: Array ko sort karlo (chhoti se badi taraf)
//         int count = 0;
//         if (n < 3) {
//             return 0; // agar 3 se kam sides hain to triangle possible hi nahi
//         }

//         // Step 2: sabse badi side ko fix karo (arr[k])
//         for (int k = n - 1; k >= 2; k--) { // arr[k] ko largest side maana
//             int i = 0, j = k - 1; // i aur j do pointers: chhoti aur badi side dhoondhne ke liye

//             // Step 3: two pointer se pairs check karte hain
//             while (i < j) {
//                 if (arr[i] + arr[j] > arr[k]) {
//                     // agar arr[i] + arr[j] > arr[k], to arr[i]..arr[j-1] sabhi valid hain
//                     count += (j - i); // itne triangles banenge
//                     j--; // ek chhoti side lene ke liye j ko piche le jao
//                 } else {
//                     i++; // sum chhota hai, to i ko aage badhao (badi value lene ke liye)
//                 }
//             }
//         }

//         return count; // total valid triangles
//     }
// };

class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // sort karlo
        int count = 0;

        // do chhoti sides fix karo
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int sum = arr[i] + arr[j];

                // binary search to find largest k such that arr[k] < sum
                int low = j + 1, high = n - 1, k = j;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (arr[mid] < sum) {
                        k = mid;       // mid valid hai
                        low = mid + 1; // aur bada element try karo
                    } else {
                        high = mid - 1; // chhota element try karo
                    }
                }

                // jitne elements j+1..k hain, sab valid hain
                count += (k - j);
            }
        }
        return count;
    }
};

