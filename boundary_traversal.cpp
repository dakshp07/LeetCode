class Solution {
public:
    // fucntion for checking ifthe node is a leaf
    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    // step 1: get the left boundary and exclude the leaf
    void leftBoundary(Node *root, vector<int> &res)
    {
        // now we go to left
        Node *curr=root->left;
        // we will push the left side
        while(curr!=NULL)
        {
            // we only push if we dnt have a leaf
            if(!isLeaf(curr)) res.push_back(curr->data);
            // we update if the curr->left aint null
            if(curr->left!=NULL) curr=curr->left;
            // lets say the left sint there we go to right
            else curr=curr->right;
        }
    }
    // step 2: now we get the leaf nodes
    void leafNodes(Node *root, vector<int> &res)
    {
        // we do inorder: LrootR
        // we just find all the leaf nodes by going recursively to get the left, right
        if(root->left!=NULL) leafNodes(root->left, res); // LEFT
        if(isLeaf(root)) // root
        {
            res.push_back(root->data);
            return;
        }
        if(root->right!=NULL) leafNodes(root->right, res); // RIGHT
    }
    // step 3: we now need the right boundary
    void rightBoundary(Node *root, vector<int> &res)
    {
        // we need them in anticlockwise
        // so we store them in temp array and move to res in reverse fashion
        Node *curr=root->right;
        vector<int> temp;
        while(curr!=NULL)
        {
            // we check leaf
            if(!isLeaf(curr)) temp.push_back(curr->data);
            // now change the node
            if(curr->right!=NULL) curr=curr->right;
            // if the right are done we go to left
            else curr=curr->left;
        }
        // now we move cntent from temp to res
        for(int i=temp.size()-1; i>=0; i--)
        {
            res.push_back(temp[i]);
        }
    }
    vector<int> boundary(Node *root)
    {
        // in order to get the boundary nodes we have to peform 3 steps
        // step 1: get the left boundary exclude leaf
        // step 2: get the leaf nodes
        // step 3: get the right boundary in reverse and exclude leaf
        
        // we intially push the root to our ds ie vector
        vector<int> res;
        if(root==NULL) return res;  
        // we also check if the node isnt a leaf
        if(!isLeaf(root)) res.push_back(root->data);
        
        // now we call function in order of 1, 2, 3
        leftBoundary(root, res);
        leafNodes(root, res);
        rightBoundary(root, res);
        return res;
    }
};
