// Time: O(n), Space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            if (next) {
                curr->next = next->next;
                next->next = head;
                head = next;
            }
            else break;
        }
        return head;
    }
};