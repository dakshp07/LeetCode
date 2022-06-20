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
    void deleteNode(ListNode* node) {
        // aapne ko head nhi diya sirf node diya hain
        // next waale ki value se replace karo delete node ki value
        // or next ko next, next pe daaldo
        int newVal=node->next->val; // next waale ki value store ki
        node->val=newVal; // delete waale node ko de di value
        node->next=node->next->next; // or uska next next next se update kardiya
    }
};