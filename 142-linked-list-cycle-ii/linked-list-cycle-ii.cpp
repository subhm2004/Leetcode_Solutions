/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // Do pointers banate hain - ek slow aur ek fast
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Floyd's Cycle Detection Algorithm (Tortoise and Hare wala method)
        while (fast && fast->next) {
            // Slow pointer ek step move karta hai
            slow = slow->next;
            // Fast pointer do step move karta hai
            fast = fast->next->next;
            
            // Agar dono pointers mil gaye, matlab cycle hai
            if (slow == fast) {
                // Ab cycle ka starting point dhundhna hai
                // Slow pointer ko head pe wapas bhej dete hain
                slow = head;
                
                // Ab dono pointers ko ek-ek step move karte hain
                // Jahan ye mil jayenge, wahi cycle ka start point hoga
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                // Cycle ka starting node return kar dete hain
                return slow;
            }
        }
        
        // Agar yahan tak pahunche, matlab koi cycle nahi hai
        return nullptr;
    }
};