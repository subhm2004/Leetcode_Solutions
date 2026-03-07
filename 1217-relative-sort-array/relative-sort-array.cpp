class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;

        map<int,int>freq;
        for(auto& val: arr1){
            freq[val]++;
        }

        for(auto& num :arr2){
            while(freq[num] > 0){
                ans.push_back(num);
                freq[num]--;
            }
        }
        for(auto& [num ,f]:freq){
            while(f--){
                ans.push_back(num);
            }
        }
        return ans;
    }
};