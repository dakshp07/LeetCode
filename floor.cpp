int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    // similar to ceil
    int ans=-1;
    while(root!=NULL)
    {
        // if root is equal to x
        if(root->val==X)
        {
            ans=root->val;
            return ans;
        }
        // if root > X
        else if(root->val>X)
        {
            // in order to get close we go to left as we need "the greatest value smaller than X"
            root=root->left;
        }
        // if root < X
        else
        {
            // update ans and keep on moving to right to get "the greatest value smaller than X"
            ans=root->val;
            root=root->right;
        }
    }
    return ans;
}
