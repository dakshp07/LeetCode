/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // to get a string we do BFS
        if(root==NULL) return "";
        queue<TreeNode *> q;
        q.push(root);
        string ans="";
        while(!q.empty())
        {
            int sz=q.size();
            auto it=q.front();
            q.pop();
            if(it==NULL) ans.append("#,"); // if null node then add # to string
            else ans.append(to_string(it->val)+','); // add the value to string if node isnt null
            if(it!=NULL)
            {
                // keep on traversing if node isnt null
                q.push(it->left);
                q.push(it->right);
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // lets make our tree from string
        if(data.size() == 0) return NULL; // if empty we return null
        stringstream s(data); // make a strem to get data
        string str;
        getline(s, str, ','); // start with , as delimeter
        TreeNode *root = new TreeNode(stoi(str)); // our root
        queue<TreeNode*> q; // for BFS
        q.push(root); // push root
        while(!q.empty()) {
            TreeNode *node = q.front(); // BFS 
            q.pop(); 
            getline(s, str, ',');
            if(str == "#") 
            { 
                // if there's a hash, means no left and right
                node->left = NULL; 
            }
            else 
            {
                // if not # means they have left and right, so push to root
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            // similary do for right as we did for left
            if(str == "#") 
            {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));