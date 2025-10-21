class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int curr_num = 1; // stream se current number (1 se start)

        for (int num : target) {
            // jab tak target number tak nahi pahuchte
            // tab tak har number push + pop karte rahenge
            while (curr_num < num) {
                ans.push_back("Push"); // stream se number uthaya
                ans.push_back("Pop");  // hume nahi chahiye tha, hata diya
                curr_num++;
            }

            // jab target number mil gaya
            ans.push_back("Push"); // isko stack me rakho
            curr_num++;
        }

        return ans;
    }
};