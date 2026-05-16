class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);

        int give = 1;  
        int i = 0;    

        // Jab tak candies hain, distribute karte raho
        while (candies > 0) {

            ans[i] += min(give, candies);

            candies -= give;          
            give++;                    
            i = (i + 1) % num_people; 
        }

        return ans;
    }
};