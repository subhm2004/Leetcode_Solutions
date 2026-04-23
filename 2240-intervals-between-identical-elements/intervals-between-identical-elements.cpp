class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
    int n = arr.size();
    vector<long long> result(n, 0);
    
    unordered_map<int, long long> count, prefix_sum;
    
    /* 
     * LEFT → RIGHT PASS (left side ka contribution)
     *
     * Jab hum index i pe hain, left mein k same elements
     * aa chuke hain at indices j1, j2, ... jk
     *
     * Kyunki i > j (left wale indices chhote hain):
     *   |i - j1| + |i - j2| + ... + |i - jk|
     *   = (i - j1) + (i - j2) + ... + (i - jk)
     *   = (i + i + ... k times) - (j1 + j2 + ... + jk)
     *   = i*k - prefix_sum
     */
    for (int i = 0; i < n; i++) {
        int v = arr[i];
        
        long long k = count[v];
        long long s = prefix_sum[v];
        
        result[i] += (long long)i * k - s;  // i*k - (j1+j2+...+jk)
        
        count[v]++;
        prefix_sum[v] += i;
    }
    
    count.clear();
    prefix_sum.clear();
    
    /* 
     * RIGHT → LEFT PASS (right side ka contribution)
     *
     * Jab hum index i pe hain, right mein k same elements
     * aa chuke hain at indices j1, j2, ... jk
     *
     * Kyunki j > i (right wale indices bade hain):
     *   |i - j1| + |i - j2| + ... + |i - jk|
     *   = (j1 - i) + (j2 - i) + ... + (jk - i)
     *   = (j1 + j2 + ... + jk) - (i + i + ... k times)
     *   = prefix_sum - i*k
     */
    for (int i = n - 1; i >= 0; i--) {
        int v = arr[i];
        
        long long k = count[v];
        long long s = prefix_sum[v];
        
        result[i] += s - (long long)i * k;  // (j1+j2+...+jk) - i*k
        
        count[v]++;
        prefix_sum[v] += i;
    }
    
    return result;
    }
};