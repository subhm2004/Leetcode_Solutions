class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Step 1: Har character ka last occurrence store karna
        vector<int> lastIndex(26, 0); // Ek array banaya jisme 26 characters ke liye jagah hai (a-z).
        for (int i = 0; i < s.length(); ++i) {
            lastIndex[s[i] - 'a'] = i; // Har character ka last index store kar diya.
        }

        // Step 2: String ko partitions mein todna
        vector<int> result; // Yeh result vector hai jisme partitions ki size store karenge.
        int start = 0, end = 0; // Partition ka start aur end track karne ke liye.

        for (int i = 0; i < s.length(); ++i) {
            end = max(end, lastIndex[s[i] - 'a']); // Current character ka last occurrence dekha aur end update kiya.

            if (i == end) { // Agar current index end tak pahuch gaya, toh partition complete.
                result.push_back(end - start + 1); // Partition ka size result mein daal diya.
                start = i + 1; // Naya partition start kar diya.
            }
        }

        return result; // Sare partitions ki sizes return kar di.
    }
};
