typedef long long ll;
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1) return {};
        vector<ll> ans;
        ll curr_num = 2;
        ll total = 0;
        
        while (total + curr_num <= finalSum){
            ans.push_back(curr_num);
            total += curr_num;
            curr_num += 2;
        }
        
        ll excess_sum = finalSum - total;
        if(excess_sum>0){
            ans.back() += excess_sum;
        }
        
        return ans;
        
    }
};