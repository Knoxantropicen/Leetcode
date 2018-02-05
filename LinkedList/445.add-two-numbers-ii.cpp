// Time: O(n_1+n_2), Space: O(n_1+n_2)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = NULL;
        int remain = 0;
        while (!(s1.empty() && s2.empty())) {
            int sum = remain;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            if (sum > 9) {
                sum -= 10;
                remain = 1;
            }
            else remain = 0;
            ListNode* node = new ListNode(sum);
            if (head) node->next = head;
            head = node;
        }
        if (remain == 1) {
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
    }
};