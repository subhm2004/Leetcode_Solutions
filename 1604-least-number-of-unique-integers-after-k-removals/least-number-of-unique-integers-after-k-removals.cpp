class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Step 1: Har number ki frequency count karo
        unordered_map<int, int> freq;
        for (int num : arr){
            freq[num]++;
        }

        // Step 2: Sab frequencies ko ek vector me daal do
        vector<int> freq_count;
        for (auto& it : freq){
            freq_count.push_back(it.second);
        }

        // Step 3: Frequencies ko ascending order me sort karo
        sort(freq_count.begin(), freq_count.end());

        int unique_left = freq_count.size(); 

        // Step 4 k ke hisaab se numbers remove karo
        for (int f : freq_count) {
            if (k >= f) {
                k -= f;       // Is number ke saare occurrences remove kar do
                unique_left--; // Ek unique number kam ho gaya
            }
            else{
                break;  
            }
        }

        return unique_left;  
    }
};
