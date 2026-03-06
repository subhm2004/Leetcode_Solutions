class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
         unordered_map<int,int> freq;

        for(int x : nums){
            if(x % 2 == 0){
                freq[x]++;
            }
        }

        int ans = -1;
        int max_freq = 0;

        for(auto [num, f] : freq){

            if(f > max_freq || (f == max_freq && num < ans)){
                max_freq = f;
                ans = num;
            }
        }

        return ans;
    }
};