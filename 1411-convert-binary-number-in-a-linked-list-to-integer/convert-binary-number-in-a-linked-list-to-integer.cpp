// class Solution {   // ye fir bhi badhiya Solution laga mujhe 
//  public:
//   int getDecimalValue(ListNode* head) {
//     int ans = 0;

//     while (head != nullptr) {
//       ans = ans * 2 + head->val;
//       head = head->next;
//     }

//     return ans;
//   }
// };

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Solution {
public:
    // \U0001f501 Iterative Reverse
    ListNode* reverse_Iterative(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    // \U0001f501 Recursive Reverse
    ListNode* reverse_Recursive(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverse_Recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

     int getDecimalValue(ListNode* head) {
         // head = reverse_Iterative(head);
        head = reverse_Recursive(head);

        int ans = 0, power = 0;

        while (head) {
            ans += head->val * pow(2, power);
            power++;
            head = head->next;
        }

        return ans;
    }
};