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
    ListNode *detectCycle(ListNode *head) {
        // we can use the standard method to find cycle
        // ie use a set and push all next nodes in set
        // if we come across any node which was already there in set we return true as its a cycle
        // here instead of true we can return the node
        // tc: O(n) for traversal and O(n) for sc as we use set
        
        // much better way would to use fast, slow pointer thing
        // but we will have another pointer which starts a lil late
        // so we find the cycle first through fast, slow and the third pointer will be used to find node
        if(head==NULL || head->next==NULL) // if we are the last or the next is last
        {
            return NULL;
        }
        ListNode *fast, *slow, *track;
        // all of them will start from head
        fast=head;
        slow=head;
        track=head;
        // fast, slow starts as usual by 2, 1 steps each
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) // if we get a cycle
            {
                // now we start our track pointer
                // now track will traverse the list till slow and they collide
                // we do track with slow because slow has the cycle node wherease fast is at the next node where cycle was formed as it was taking 2 steps at a time
                while(slow!=track)
                {
                    // both will take 1 step each
                    slow=slow->next;
                    track=track->next;
                }
                return track; // once they collide track will have the cycle node
            }
        }
        return NULL;
    }
};