class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        set<pair<int, int>> elements; // {value, index}

        for (int i = indexDifference; i < n; ++i) {
            // Insert the element at i - indexDifference into the set
            elements.insert({nums[i - indexDifference], i - indexDifference});

            // Check if there's any value >= nums[i] + valueDifference
            auto it1 = elements.lower_bound({nums[i] + valueDifference, -1});
            if (it1 != elements.end()) {
                return {i, it1->second};
            }

            // Check if there's any value <= nums[i] - valueDifference
            auto it2 = elements.lower_bound({nums[i] - valueDifference + 1, -1});
            if (it2 != elements.begin()) {
                --it2;
                return {i, it2->second};
            }
        }

        return {-1, -1};
    }
};
