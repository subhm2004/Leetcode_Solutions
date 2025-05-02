class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Sort both arrays to get the smallest elements easily
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Step 2: Check for any common digit
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j])
                return nums1[i]; // Agar common digit mil gaya to wahi return karo
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        // Step 3: No common digit, to smallest dono ka combine karke minimum banate hain
        int a = nums1[0];
        int b = nums2[0];
        return min(a * 10 + b, b * 10 + a);
    }
};
