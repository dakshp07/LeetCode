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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // dummy node banao 
        // temp node is equal to dummy
        // sum and carry chalega
        ListNode *dummy=new ListNode();
        ListNode *temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry) // we will iterate till we reach l1 ends or l2 ends or carry becomes zero
        {
            int sum=0;
            if(l1!=NULL) sum+=l1->val, l1=l1->next; // add val and update next
            if(l2!=NULL) sum+=l2->val, l2=l2->next;
            sum+=carry;
            carry=sum/10; // if we get 10 as sum then sum/10=10/10 will carry ie 1
            ListNode *node=new ListNode(sum%10); // and the other bit from carry will be 10%10 (ie 0)
            temp->next=node; // assign temp to node
            temp=temp->next; // go to next in temp
        }
        return dummy->next;
    }
};