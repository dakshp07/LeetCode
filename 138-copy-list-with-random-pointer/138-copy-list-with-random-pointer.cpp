/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // one of the brute force ways is to make a hashset which will store node, node
        // we can now traverse and store the values in set, return them back using a list
        // but this will take some extra space
        // more optimal: create the nodes on top of old list
        // we can get val, next from old one. But random ptr is tough to get
        // so we use some logic to get random ptr value
        // step 1: create deep node, step 2: random nodes connected, step 3: next node points
        // tc for step 1: O(n), for step 2: O(n), for step 3: O(n)~=O(n)
        // sc: O(1) constant
        
        // step 1: make copy of each node,
        // and link them together side-by-side in a single list.
        Node *iter=head; // traverse
        Node *front=head; // keep track of head of new clone list
        while(iter!=NULL)
        {
            front=iter->next;
            Node *copy=new Node(iter->val); // deep copy of iter
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        // step 2: assign random pointers for the copy nodes.
        iter=head;
        while(iter!=NULL)
        {
            if(iter->random!=NULL)
            {
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        // step 3: restore the original list, and extract the copy list.
        iter=head;
        Node *psuedohead=new Node(0);
        Node *copy=psuedohead;
        while(iter!=NULL)
        {
            front=iter->next->next;
            // extract the copy
            copy->next=iter->next;
            // restore the original list
            iter->next=front;
            copy=copy->next;
            iter=front;
        }
        return psuedohead->next;
    }
};