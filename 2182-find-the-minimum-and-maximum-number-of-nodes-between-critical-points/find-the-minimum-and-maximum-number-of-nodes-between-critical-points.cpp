class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, 0};
        int firstCritical = -1, prevCritical = -1, index = 0;

        ListNode* prev = head;
        ListNode* curr = head->next;
        index = 1;

        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                if (firstCritical == -1) {
                    firstCritical = index;
                    prevCritical = index;
                } else {
                    ans[0] = min(ans[0], index - prevCritical);
                    ans[1] = max(ans[1], index - firstCritical);
                    prevCritical = index;
                }
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (firstCritical == prevCritical) {
            return {-1, -1};
        }
        ans[0] = (ans[0] == INT_MAX) ? -1 : ans[0];
        return ans;
    }
};
