class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int count = 0;

        for (int i = 0; i < n; ) {
            // Har shipment ki shuruat index i se hoti hai
            int max_weight = weight[i];  // Current shipment ka maximum weight track karte hain
            bool found = false;         // Track karte hain ki valid shipment mili ya nahi

            // i+1 se n-1 tak sare elements check karte hain
            for (int j = i + 1; j < n; j++) {
                // Current element ko include karke max_weight update karte hain
                max_weight = max(max_weight, weight[j]);

                // Check karte hain ki current element max_weight se chota hai ya nahi
                // Agar chota hai to yahan pe shipment end ho jayegi (balanced condition)
                if (weight[j] < max_weight) {
                    count++;       // Ek valid shipment mil gayi
                    i = j + 1;     // Agla shipment j+1 index se start hoga
                    found = true;  // Valid shipment mil gayi hai
                    break;         // Current shipment complete, loop se bahar niklo
                }
            }

            // Agar koi valid shipment nahi mili current position se, to algorithm terminate
            if (!found) break;
        }

        return count;  // Total balanced shipments return karo
    }
};

/*
DRY RUN for test case: weight = [3, 1, 4, 2, 5]

Initial: n=5, count=0

ITERATION 1:
i=0, max_weight=3 (weight[0])
  j=1: max_weight = max(3,1) = 3
       weight[1]=1 < max_weight=3? YES
       count=1, i=2 (j+1), found=true, break

ITERATION 2: 
i=2, max_weight=4 (weight[2])
  j=3: max_weight = max(4,2) = 4
       weight[3]=2 < max_weight=4? YES  
       count=2, i=4 (j+1), found=true, break

ITERATION 3:
i=4, max_weight=5 (weight[4])
  j=5: j >= n, inner loop exits
  found=false, outer loop breaks

RESULT: count=2

Shipments formed:
1. [3,1] - indices 0 to 1
2. [4,2] - indices 2 to 3
Element 5 at index 4 remains unshipped

*/