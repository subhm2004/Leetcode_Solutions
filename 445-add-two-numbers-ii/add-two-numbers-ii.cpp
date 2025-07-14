class Solution {
public:
    // Reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse both input lists (MSD -> LSD → becomes LSD -> MSD)
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* result = nullptr;
        int carry = 0;

        // Add both reversed lists
        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = result;
            result = newNode;
        }

        return result; // This is already in MSD to LSD order
    }
};
