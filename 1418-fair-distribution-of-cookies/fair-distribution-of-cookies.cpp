class Solution {
public:
   bool canDistribute(int idx, const vector<int>& cookies, int k, int limit, vector<int>& children) {
        if (idx == cookies.size()) {
            return true;  // Successfully assigned all cookies
        }

        for (int i = 0; i < k; ++i) {
            if (children[i] + cookies[idx] <= limit) {
                children[i] += cookies[idx];

                if (canDistribute(idx + 1, cookies, k, limit, children)) {
                    return true;
                }

                children[i] -= cookies[idx];

                // Pruning: If this child is empty and can't take the cookie, no need to try further.
                if (children[i] == 0) {
                    break;
                }
            }
        }

        return false;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int low = *max_element(cookies.begin(), cookies.end());
        int high = accumulate(cookies.begin(), cookies.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<int> children(k, 0);
            
            if (canDistribute(0, cookies, k, mid, children)) {
                ans = mid;
                high = mid - 1;  // Try a smaller unfairness
            } else {
                low = mid + 1;   // Increase unfairness threshold
            }
        }

        return ans;
    }
};
