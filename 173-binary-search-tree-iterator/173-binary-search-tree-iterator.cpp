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
class BSTIterator {
public:
    stack<TreeNode *> st;
    // stack will be used to push everything in the left side of root
    // if we ecnounter a next we return stack top
    // and push all the right child of the top into stack
    // has next is basically returning if stack is empty or not
    BSTIterator(TreeNode* root) {
        // constructor will be used to initialize stack by adding all nodes
        pushLeft(root);
    }
    
    int next() {
        // return top, pop ele and add new nodes
        TreeNode *tp=st.top();
        st.pop();
        pushLeft(tp->right);
        return tp->val;
    }
    
    bool hasNext() {
        // check if stack has something or not
        return st.size();
    }
    // function to push all nodes
    void pushLeft(TreeNode *root){
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */