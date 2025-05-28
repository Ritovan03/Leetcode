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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i; // Map value to index for quick lookup
        }
        int preorder_index = 0; // Pointer to traverse preorder array
        return build(preorder, inorder_map, preorder_index, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorder_map, 
                    int& preorder_index, int left, int right) {
        if (left > right) return nullptr; // Base case
        
        int root_val = preorder[preorder_index++]; // Get the root value
        TreeNode* root = new TreeNode(root_val);   // Create the root node
        
        int inorder_index = inorder_map[root_val]; // Get the root index in inorder
        
        // Recursively build the left and right subtrees
        root->left = build(preorder, inorder_map, preorder_index, left, inorder_index - 1);
        root->right = build(preorder, inorder_map, preorder_index, inorder_index + 1, right);
        
        return root;
    }
    
};