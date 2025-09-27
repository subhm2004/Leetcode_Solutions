// =============================
// Mo's Algorithm Class
// =============================
class MosAlgorithm {
private:
    vector<int> arr;                   // compressed array
    vector<int> freq;                  // frequency of each element
    map<int, set<int>> freq_to_vals;   // freq -> set of values
    int BLOCK_SIZE;
    vector<int> rev_map;               // map back compressed -> original value

public:
    struct Query {
        int l, r, threshold, idx;
    };

    MosAlgorithm(const vector<int> &compressed, const vector<int> &rev_map_input) {
        arr = compressed;
        rev_map = rev_map_input;
        int n = arr.size();
        BLOCK_SIZE = sqrt(n);
        freq.assign(rev_map.size(), 0);
    }

    // Mo comparator
    bool compare(const Query &a, const Query &b) {
        int block_a = a.l / BLOCK_SIZE, block_b = b.l / BLOCK_SIZE;
        if (block_a != block_b) return block_a < block_b;
        return (block_a & 1) ? (a.r < b.r) : (a.r > b.r);
    }

    // Add element
    void add(int idx) {
        int x = arr[idx];
        int old_f = freq[x], new_f = old_f + 1;
        if (old_f > 0) {
            freq_to_vals[old_f].erase(x);
            if (freq_to_vals[old_f].empty()) freq_to_vals.erase(old_f);
        }
        freq[x] = new_f;
        freq_to_vals[new_f].insert(x);
    }

    // Remove element
    void remove(int idx) {
        int x = arr[idx];
        int old_f = freq[x], new_f = old_f - 1;
        freq_to_vals[old_f].erase(x);
        if (freq_to_vals[old_f].empty()) freq_to_vals.erase(old_f);
        freq[x] = new_f;
        if (new_f > 0) freq_to_vals[new_f].insert(x);
    }

    // Answer for one query
    int get_answer(int threshold) {
        if (freq_to_vals.empty()) return -1;
        auto it = freq_to_vals.rbegin(); // max frequency
        int best_freq = it->first;
        if (best_freq < threshold) return -1;
        int best_val = *it->second.begin(); // smallest among max freq
        return rev_map[best_val];
    }

    // Process queries
    vector<int> process_queries(vector<Query> &queries) {
        sort(queries.begin(), queries.end(),
             [this](Query a, Query b){ return compare(a, b); });

        vector<int> answer(queries.size());
        int cur_l = 0, cur_r = -1;

        for (auto &q : queries) {
            while (cur_l > q.l) add(--cur_l);
            while (cur_r < q.r) add(++cur_r);
            while (cur_l < q.l) remove(cur_l++);
            while (cur_r > q.r) remove(cur_r--);
            answer[q.idx] = get_answer(q.threshold);
        }
        return answer;
    }
};

// =============================
// Solution Class
// =============================
class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // ✅ Coordinate Compression using set
        set<int> st(nums.begin(), nums.end());
        unordered_map<int,int> compress;
        vector<int> rev_map(st.size());
        int id = 0;
        for (int x : st) {
            compress[x] = id;
            rev_map[id] = x;
            id++;
        }

        vector<int> compressed(n);
        for (int i = 0; i < n; i++) {
            compressed[i] = compress[nums[i]];
        }

        // ✅ Prepare queries
        vector<MosAlgorithm::Query> qs;
        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }

        // ✅ Run Mo's Algorithm
        MosAlgorithm mo(compressed, rev_map);
        return mo.process_queries(qs);
    }
};
