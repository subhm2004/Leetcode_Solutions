class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        // Stack ka use karenge jisme hum current element ka value aur count ko store karenge
        stack<pair<int, int>> s;
        long long answer = 0;
        
        // Har element ke liye loop
        for (int i = 0; i < nums.size(); i++) {
            // Agar stack mein kuch elements hain aur stack ka top element current element se chhota hai
            // toh stack se pop karenge
            while (!s.empty() && s.top().first < nums[i]) {
                s.pop(); // Pop karte hain agar top element current element se chhota hai
            }
            
            // Agar stack empty hai ya stack ka top element current element se bada hai
            // toh current element ko stack mein push karenge, aur uska count 0 set karenge
            if (s.empty() || s.top().first > nums[i]) {
                s.push({nums[i], 0});
            }
            
            // Current element ke count ko increment karenge
            s.top().second += 1;
            
            // 'answer' mein current element ka count add karenge
            answer += s.top().second;
        }
        
        // Total valid subarrays ka count return karenge
        return answer;
    }
};
