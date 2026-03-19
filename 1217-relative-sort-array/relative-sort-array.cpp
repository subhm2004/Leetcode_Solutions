class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> ans;
        map<int, int> freq;
        for (auto val : arr1) {
            freq[val]++;
        }

        for (int i = 0; i < arr2.size(); i++) {
            while (freq[arr2[i]]) {
                ans.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }

        for(auto [value , f] : freq){
            while(f){
                ans.push_back(value);
                f--;
            }
        }
        return ans;
    }

};