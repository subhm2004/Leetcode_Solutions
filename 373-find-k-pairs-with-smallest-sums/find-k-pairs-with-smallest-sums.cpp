class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        // Min heap: {sum, i, j}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> min_heap;

        // Pehle nums1 ke first k elements ko nums2[0] ke saath daalo
        for (int i = 0; i < nums1.size() && i < k; i++) {
            min_heap.push({nums1[i] + nums2[0], i, 0});
        }

        // Heap se k pairs nikalo
        while (k-- > 0 && !min_heap.empty()) {
            auto [sum, i, j] = min_heap.top();
            min_heap.pop();
            ans.push_back({nums1[i], nums2[j]});

            // Agla candidate push karo
            if (j + 1 < nums2.size()) {
                min_heap.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return ans;
    }
};
