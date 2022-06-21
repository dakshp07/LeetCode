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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // one is to start traversing one list and check every node in other one
        // tc will be O(l1*l2)
        // more optimal is to keep 2 dummy nodes and get the length of both list
        // the one who is bigger make there dummy node traverse the first step as diff of length
        // tc will be O(bigger len)+O(diff)+O(shorter len)=O(2*bigger)
        // but its very complicated, fnd length diff and traverse
        // the other approach is to iterate the two dummy nodes two times of their length
        if(headA==NULL|| headB==NULL) return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        // if both list have diff leng we stop after second iteration
        while(a!=b)
        {
            // at end of first iteration we need to set the a, b back to head of their resp lists
            a=a==NULL?headA: a->next;
            b=b==NULL?headB: b->next;
        }
        return a;
    }
};