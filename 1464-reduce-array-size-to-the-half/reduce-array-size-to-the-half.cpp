class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int half = arr.size() / 2;

        unordered_map<int, int> freqMap;
        for (int num : arr)
            freqMap[num]++;

        vector<int> freq;
        for (auto& [num, count] : freqMap)
            freq.push_back(count);

        sort(freq.begin(), freq.end(), greater<int>()); // decreasing order me hai 

        int removed = 0, ans = 0;
        for (int i = 0; i < freq.size() && removed < half; ++i) {
            removed += freq[i];
            ans++;
        }

        return ans;
    }
};
