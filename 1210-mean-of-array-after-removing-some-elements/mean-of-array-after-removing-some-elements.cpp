class Solution {
public:
    double trimMean(vector<int>& arr) {
        // Step 1: Calculate the offset, jo 5% hai
        int offset = arr.size() / 20;  // 5% of the array size

        // Step 2: Sort the array to easily remove the top and bottom 5% elements
        sort(arr.begin(), arr.end());

        // Step 3: Remove the first 'offset' and last 'offset' elements
        arr = vector<int>(arr.begin() + offset, arr.end() - offset);

        // Step 4: Calculate the sum of the remaining elements
        double sum = accumulate(arr.begin(), arr.end(), 0.0);

        // Step 5: Calculate and return the mean of remaining elements
        return sum / arr.size();
    }
};
