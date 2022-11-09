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
    ListNode* deleteDuplicates(ListNode* head) {
        // create a fake node that acts like a fake head of list pointing to the original head...
        ListNode* fake = new ListNode(0);
        // fake node points to the original head...
        fake->next = head;
        ListNode* pre = fake;     //pointing to last node which has no duplicate...
        ListNode* curr = head;      // To traverse the linked list...
        // Now we traverse nodes and do the process...
        while (curr != NULL) {
            // Create a loop until the current and previous values are same, keep updating curr...
            while (curr->next != NULL && pre->next->val == curr->next->val)
                curr = curr->next;
            // if curr has non-duplicate value, move the pre pointer to next node...
            if (pre->next == curr)
                pre = pre->next;
            // If curr is updated to the last duplicate value, discard it & connect pre and curr->next...
            else
                pre->next = curr->next;
                // Move curr forward...
                // In next iteration, we still need to check whether curr points to duplicate value...
                curr = curr->next;
        }
        // Return the linked list...
        return fake->next;
    }
};