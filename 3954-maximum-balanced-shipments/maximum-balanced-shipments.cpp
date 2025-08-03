class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int count = 0;

        for (int i = 0; i < n; ) {  
            int maxWeight = weight[i];
            bool found = false;

            for (int j = i + 1; j < n; j++) {
                maxWeight = max(maxWeight, weight[j]);

                // Check if current end j is making a valid shipment
                if (weight[j] < maxWeight) {
                    count++;       // Shipment mil gaya 
                    i = j + 1;     // Next i shipment ke baad se start hogi
                    found = true;
                    break;
                }
            }

            // Agar koi shipment nahi mili, to aage badho
            if (!found) break;
        }

        return count;
    }
};
