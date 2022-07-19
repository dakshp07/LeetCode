void changeTree(BinaryTreeNode < int > * root) {
    // we move left, right recursively and then add the remaining sum to nodes
    if(root==NULL) return;
    int child=0;
    // we go first to left
    if(root->left) child+=(root->left->data);
    // now right
    if(root->right) child+=(root->right->data);
    // we now check if parent value is sum of left right nodes
    if(child>=root->data) root->data=child; // if the child has greater value then we assign root value as the child data
    else
    {
        if(root->left) root->left->data=root->data; // we assign the left node the value
        if(root->right) root->right->data=root->data; // or else we do that for right
    }
    changeTree(root->left); // do recursively for root->left
    changeTree(root->right);
    // we set the total of sum of left and right to our main root
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left or root->right) root->data=tot;
}  
