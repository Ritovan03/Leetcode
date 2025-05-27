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
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null,";
            }
        }

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val;
        getline(ss, val, ','); // Read the first value

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process left child
            if (getline(ss, val, ',')) {
                if (val != "null") {
                    TreeNode* leftNode = new TreeNode(stoi(val));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Process right child
            if (getline(ss, val, ',')) {
                if (val != "null") {
                    TreeNode* rightNode = new TreeNode(stoi(val));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }




    /*
    Additional logic which i came up with (intuitive soln) BUT WILL NOT WORK AS DUPLICATES EXIOST IN THE TREE
     //preorder tree building
    void serializeHelperPreorder(TreeNode* root,string &ans)
    {
        if(root == nullptr)
        {
            return ;
        }
        ans+=to_string(root->val) + ",";
        serializeHelperPreorder(root->left,ans);
        serializeHelperPreorder(root->right,ans);
        
    }
    //inorder tree building
    void serializeHelperInorder(TreeNode* root,string &ans)
    {
        if(root == nullptr)
        {
            return ;
        }
        
        serializeHelperInorder(root->left,ans);
        ans+=to_string(root->val) + ",";
        serializeHelperInorder(root->right,ans);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // get string for inorder
        string inans = "";
        serializeHelperInorder(TreeNode* root,inans);

        // get string for preorder
        string preans = "";
        serializeHelperPreorder(TreeNode* root,preans);
        string ans = inans + "|" + preans;
        //return string = (instring + | + prestring)
        returns ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //get inorder string from 0 to |

        //get preorder string from | to n-1
        //construct tree from inorder and preorder and return that 
        
    }
    */
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));