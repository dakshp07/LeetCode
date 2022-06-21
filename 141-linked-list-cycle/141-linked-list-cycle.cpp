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
        // extra set ka use karenge
        // set main saare nodes daalte jaayenge agar kahi same node aaya joh set main hain toh true
        unordered_set<ListNode*> st; // set store karega
        ListNode *temp=head; // start traverse
        while(temp!=NULL) // traverse till list ends
        {
            if(st.find(temp)!=st.end()) // agar set main tha
            {
                return true; // return true
            }
            st.insert(temp); // insert the node in set
            temp=temp->next; // update temp to next
        }
        return false; // no cycle toh false
    }
};