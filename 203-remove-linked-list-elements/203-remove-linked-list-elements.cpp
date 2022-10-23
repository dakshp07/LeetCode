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
    ListNode* removeSameNodes(ListNode* head, int val)
    {
        // base case
        // if head becomes null we return null
        if(head==NULL) return NULL;
        // now we call recursively for next nodes
        head->next=removeSameNodes(head->next, val);
        
        // if our head is now at a node which is ==val
        // we unlink it and point the node to next
        if(head->val==val) return head->next;
        // if it !=val we return just the head
        return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
        // we can call recursively for the next nodes
        // and if they are ==val we unlink them and join the current node with next
        // tc: O(n) and sc: O(n) for recursion stack space
        // the same thing can be done iteratively, tc: O(n) and sc: O(1)
        return removeSameNodes(head, val);
    }
};