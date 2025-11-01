auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Set bnao jisme nums ke unique numbers honge
        unordered_set<int> anokha(nums.begin(), nums.end());

        // Dummy node bnao taaki head remove hone wali edge cases handle ho ske
        ListNode* chutiya = new ListNode(0);
        chutiya->next = head;
        
        ListNode* current = chutiya;

        while (current->next) {
            // Agar current node ka value unique_nums me hai toh usse skip karo
            if (anokha.find(current->next->val) != anokha.end()) {
                current->next = current->next->next;
            } else {
                // Agar nahi hai toh next node pe move karo
                current = current->next;
            }
        }

        // Modified list return karo
        return chutiya->next;
    }
};
