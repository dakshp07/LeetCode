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
    ListNode* reverseList(ListNode* head) {
        // one way could be: use arr to store data and then reverse the array
        // other way:
        // phele toh curr head ko NULL pe daal do
        // and then NULL waale node ko connect karo with old head
        // and then do the same for every other node
        // for last node point it to NULL
        ListNode* newHead=NULL; // new head joh basically last hoga
        while(head!=NULL) // will traverse the whole list
        {
            ListNode* next=head->next; // we take next
            head->next=newHead; // and point that next to out dummy node ie newHead
            newHead=head; // update newHead as head
            head=next; // update head as next to keep traversal
        }
        return newHead;
    }
};