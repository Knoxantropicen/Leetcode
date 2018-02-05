// Time: O(n), Space: O(1)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode *curr = head;
        // insert new node between nodes in original list
        while (curr) {
        	RandomListNode *node = new RandomListNode(curr->label);
        	node->next = curr->next;
        	curr->next = node;
        	curr = node->next;
        }
        // copy random
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        // seperate two lists
        curr = head;
 		RandomListNode *newhead = head->next;
        while (curr) {
        	RandomListNode *node = curr->next;
        	curr->next = node->next;
        	curr = curr->next;
        	if (curr) node->next = curr->next;
            else node->next = NULL;
        }
        return newhead;
    }
};