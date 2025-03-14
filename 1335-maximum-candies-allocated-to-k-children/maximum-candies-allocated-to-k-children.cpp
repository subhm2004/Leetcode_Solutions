class Solution {
public:
    // Ye function candies ka total sum return karega
    long long totalCandies(vector<int>& candies) {
        long long sum = 0;
        for (int c : candies)
            sum += c;
        return sum;
    }

    // Ye function count karega ki given size ke candies kitne children ko
    // distribute ho sakte hain
    long long countChildren(vector<int>& candies, int portionSize) {
        long long total = 0;
        for (int c : candies)
            total += c / portionSize;
        return total;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = totalCandies(candies) / k;

        while (left < right) {
            int mid = (left + right) >> 1;

            // Agar mid size ke candies k children me distribute nahi ho sakte,
            // to chhota size try karo
            if (countChildren(candies, mid) < k)
                right = mid;
            else
                left = mid + 1;
        }

        return countChildren(candies, left) >= k ? left : left - 1;
    }
};
