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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;  // If the list is empty or has only one node, there can't be a cycle.
        }
        
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;      // Move slow pointer by one step
            fast = fast->next->next; // Move fast pointer by two steps

            if (slow == fast) {
                return true;  // If slow and fast pointers meet, there is a cycle.
            }
        }
        
        return false; // If fast pointer reaches the end, there is no cycle.
    }
};
