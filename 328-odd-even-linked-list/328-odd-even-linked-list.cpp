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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        // lets keep two pointers and iterate over the list
        // so the idea is we keep the odd ll and even ll seperately and then add them
        // so odd starts from head and it connects all the next->next nodes
        // and even starts at head->next and it connects its next->next nodes
        // and at the end we concate the odd,even
        ListNode* odd, *even;
        // odd start at head
        odd=head;
        // even starts at head->next
        even=head->next;
        // a head node to connect odd last node with even head and return the list
        ListNode *even_head=head->next;
        // we iterate till even->next reaches end and odd->next reaches end
        while(odd->next!=NULL && even->next!=NULL)
        {
            odd->next=even->next; // connect all odd nodes
            even->next=odd->next->next; // connect all even nodes
            // now we move pointers
            odd=odd->next;
            even=even->next;
        }
        // now we connect last odd node with even head
        odd->next=even_head;
        // when we are done with editing connections we now return our head
        return head;
    }
};