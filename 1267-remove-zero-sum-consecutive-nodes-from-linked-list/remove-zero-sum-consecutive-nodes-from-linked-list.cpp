class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Dummy node laga rahe hain taaki agar head delete ho toh bhi dikkat na ho
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Map banate hain jisme hum prefix sum aur us sum pe last node ka pointer rakhenge
        unordered_map<int, ListNode*> sumToNode;

        int prefix_sum = 0;
        ListNode* node = dummy;

        // Pehla pass: har node tak ka prefix sum nikaal ke map mein store kar lo
        // Agar same sum dobara milega, toh beech ke nodes ka sum 0 hoga
        while (node) {
            prefix_sum += node->val;
            sumToNode[prefix_sum] = node;  // us sum ke last node ko map mein store karo
            node = node->next;
        }

        // Prefix sum reset kar do aur ab actual removal karte hain
        prefix_sum = 0;
        node = dummy;

        // Dusra pass: agar same prefix sum dobara milta hai,
        // toh beech ke nodes hata do by skipping them
        while (node) {
            prefix_sum += node->val;
            node->next = sumToNode[prefix_sum]->next;  // zero sum wale part skip kar rahe hain
            node = node->next;
        }

        // Dummy ke next se actual updated list milegi
        return dummy->next;
    }
};
