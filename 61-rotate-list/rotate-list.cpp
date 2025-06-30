class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        int len = getLength(head);
        int rotation_point = k % len;
        if (rotation_point == 0) return head;

        int new_end_pos = len - rotation_point - 1;
        ListNode* newHead = nullptr;
        ListNode* new_Last_Node = head;
        
        for (int i = 0; i < new_end_pos; i++) {
            new_Last_Node = new_Last_Node->next;
        }
        
        newHead = new_Last_Node->next;
        new_Last_Node->next = nullptr;
        
        ListNode* it = newHead;
        while (it->next) {
            it = it->next;
        }
        it->next = head;
        
        return newHead;
    }
};
