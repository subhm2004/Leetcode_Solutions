class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        int sum = nums[0];

        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        int x = sum;


        while (st.count(x)) {
            x++;
        }

        return x;
    }
};