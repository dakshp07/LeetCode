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
    // so we need to do a inorder traversal
    // we can use a stack as the recursion code of inorder or any traversal uses recursive stack space
    // inorder: LrootR
    // the idea is to push all the left nodes, once a left node is called we call all its right nodes and push them onto stack
    // has next will essentially check if the stack is empty or not
    stack<TreeNode*> st;
    // the below function pushes all the left nodes to stack
    void pushAllLeft(TreeNode* root)
    {
        if(root==NULL) return;
        st.push(root);
        pushAllLeft(root->left);
    }
    BSTIterator(TreeNode* root) {
        // intialize the function through this constructor
        pushAllLeft(root);
    }
    
    int next() {
        // now here we need to return the next element
        // so we return the stack top
        TreeNode* top_ele=st.top();
        st.pop();
        // and call the top_ele right ele and push them to stack
        pushAllLeft(top_ele->right);
        return top_ele->val;
    }
    
    bool hasNext() {
        // here we just check stack is empty or not
        return st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */