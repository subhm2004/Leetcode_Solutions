class Solution {
public:
    // Check karta hai ki kya `mid` number of tasks assign kiye ja sakte hain
    bool helper_function(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.begin(), workers.begin() + mid); // pehle `mid` strong workers uthaye sorted order me hi aayenge or ye (multi_set me duplicates allowed hote hai )
        int pillsUsed = 0;

        // Sabse tough `mid` tasks assign karne ki koshish (tasks ascending order mein hain)
        for (int i = mid - 1; i >= 0; i--) {
            int task = tasks[i];

            // Sabse strong worker se task karwane ki koshish
            auto it = prev(availableWorkers.end());

            if (*it >= task) {
                // Worker bina pill ke kaam kar sakta hai
                availableWorkers.erase(it);
            } else if (pillsUsed < pills) {
                // Aisa worker dhundho jo pill leke kaam kar sake
                auto it2 = availableWorkers.lower_bound(task - strength);
                if (it2 == availableWorkers.end()) return false; // koi bhi worker fit nahi

                availableWorkers.erase(it2);
                pillsUsed++;
            } else {
                return false; // pills khatam ho gaye aur koi bhi worker kaam ke layak nahi
            }
        }

        return true; // saare tasks assign ho gaye
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(), tasks.end());                         // Tasks ko kamzor se strong tak sort karo
        sort(workers.begin(), workers.end(), greater<int>());    // Strongest to weakest workers

        int low = 0, high = min(n, m);
        int ans = 0;

        // Binary search se maximum assignable tasks ka number dhundho
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (helper_function(mid, tasks, workers, pills, strength)) {
                ans = mid;       // Aur zyada try karo
                low = mid + 1;
            } else {
                high = mid - 1;  // kam try karo
            }
        }

        return ans; // maximum kitne tasks assign kiye ja sakte hain
    }
};
