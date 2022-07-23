/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator{
    stack<TreeNode *> st;
    // reverse=true -> next()
    // reverse=fale -> before()
    bool reverse=true;
public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return st.size();
    }
    int next(){
        TreeNode *tp=st.top();
        st.pop();
        if(!reverse) pushAll(tp->right);
        else pushAll(tp->left);
        return tp->val;
    }
    void pushAll(TreeNode *root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(reverse==true)
            {
                root=root->right;
            }
            else
            {
                root=root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // we use the concept of BST Iterator
        // we will use the next() from it and also create somthing called before()
        // if sum>k we call next() or else we call before()
        if(root==NULL) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};