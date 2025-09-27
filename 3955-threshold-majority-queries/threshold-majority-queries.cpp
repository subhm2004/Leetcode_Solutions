#include <bits/stdc++.h>
using namespace std;

// ============================
// Coordinate Compression
// ============================
class CoordinateCompression {
public:
    unordered_map<int,int> compress; // original -> compressed
    vector<int> rev_map;              // compressed -> original

    CoordinateCompression(const vector<int> &arr) {
        set<int> st(arr.begin(), arr.end());
        int id = 0;
        for (int x : st) {
            compress[x] = id;
            rev_map.push_back(x);
            id++;
        }
    }

    vector<int> get_compressed(const vector<int> &arr) {
        vector<int> res(arr.size());
        for (int i = 0; i < arr.size(); i++)
            res[i] = compress[arr[i]];
        return res;
    }

    int get_original(int val) {
        return rev_map[val];
    }
};

// ============================
// Mo's Algorithm for Majority Query
// ============================
class MosAlgorithm {
private:
    vector<int> arr;   // compressed array
    vector<int> freq;  // frequency of each element
    int BLOCK_SIZE;
    vector<int> rev_map;

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

    bool compare(const Query &a, const Query &b) {
        int block_a = a.l / BLOCK_SIZE;
        int block_b = b.l / BLOCK_SIZE;
        if (block_a != block_b) return block_a < block_b;
        return (block_a & 1) ? (a.r < b.r) : (a.r > b.r);
    }

    void add(int idx) {
        freq[arr[idx]]++;
    }

    void remove(int idx) {
        freq[arr[idx]]--;
    }

    int get_answer(int threshold) {
        int best_freq = 0;
        int ans = -1;

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] >= threshold) {
                if (freq[i] > best_freq || (freq[i] == best_freq && rev_map[i] < ans)) {
                    best_freq = freq[i];
                    ans = rev_map[i];
                }
            }
        }

        return ans;
    }

    vector<int> process_queries(vector<Query> &queries) {
        sort(queries.begin(), queries.end(), [this](Query a, Query b){ return compare(a,b); });

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

// ============================
// Solution Class
// ============================
class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        // 1️⃣ Coordinate Compression
        CoordinateCompression cc(nums);
        vector<int> compressed = cc.get_compressed(nums);

        // 2️⃣ Prepare queries
        vector<MosAlgorithm::Query> qs;
        for (int i = 0; i < queries.size(); i++)
            qs.push_back({queries[i][0], queries[i][1], queries[i][2], i});

        // 3️⃣ Run Mo's Algorithm
        MosAlgorithm mo(compressed, cc.rev_map);
        return mo.process_queries(qs);
    }
};
