/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Tortoise and Hare approach - same technique jo cycle detection mein use kari thi
        ListNode* slow = head;  // Slow pointer - 1 step move karta hai
        ListNode* fast = head;  // Fast pointer - 2 steps move karta hai
        
        // Jab tak fast pointer end tak nahi pahuncha
        while (fast && fast->next) {
            slow = slow->next;      // Slow 1 step
            fast = fast->next->next; // Fast 2 steps
        }
        
        // Jab fast pointer end tak pahunch jaye, slow pointer middle pe hoga
        return slow;
    }
};