// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    // we will regularly look for just next greater node than input
    int ans=-1;
    while(root!=NULL)
    {
        // if the current node == input
        if(root->data==input)
        {
            // update ans and return ans
            ans=root->data;
            return ans;
        }
        // our input is bigger
        if(input>root->data)
        {
            // we move right in order to get bogger values that are close to our input
            root=root->right;
        }
        else
        {
            // we update ans
            ans=root->data;
            // and move left to look for more smaller value
            root=root->left;
        }
    }
    return ans;
    // Your code here
}
