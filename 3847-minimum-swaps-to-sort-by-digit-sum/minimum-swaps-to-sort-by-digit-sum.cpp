class Solution {
public:
    int sum_of_digit(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = (int)nums.size();
        vector<tuple<int, int, int>> arr; // {value, digitSum, originalIndex}

        for (int i = 0; i < n; i++) {
            arr.emplace_back(nums[i], sum_of_digit(nums[i]), i);
        }

        // Sort based on digit sum, then value
        sort(arr.begin(), arr.end(), [&](const auto& a, const auto& b) {
            int sumA = get<1>(a);
            int sumB = get<1>(b);
            if (sumA == sumB)
                return get<0>(a) < get<0>(b);
            return sumA < sumB;
        });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // If already visited or already in correct position, skip
            if (visited[i] || get<2>(arr[i]) == i)
                continue;

            int cycleSize = 0;
            int j = i;

            // Traverse cycle
            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(arr[j]);
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
