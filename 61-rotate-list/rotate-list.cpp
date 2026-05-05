class Solution {
public:
    int get_length_of_ll(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int L = get_length_of_ll(head);
        k = k % L;
        if (k == 0) 
            return head;

        // Step 1: find new tail position
        int new_tailPos = L - k - 1;

        // Step 2: reach new tail
        ListNode* new_tail = head;
        for (int i = 0; i < new_tailPos; i++) {
            new_tail = new_tail->next;
        }

        // Step 3: new head
        ListNode* new_head = new_tail->next;

        // Step 4: break
        new_tail->next = nullptr;

        // Step 5: connect last part to head
        ListNode* temp = new_head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;

        return new_head;
    }
};