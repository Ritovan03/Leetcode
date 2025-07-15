/**
 * Definition for a binary tree node.
  struct TreeNode {
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
    TreeNode* helper(TreeNode* root,int val)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->val == val)
        {
            return root;
        }
        if(root->val<val)
        {
            return helper(root->right,val);
        }
        else
        {
            return helper(root->left,val);
        }
        return nullptr;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        //search recursive function
        TreeNode* req = helper(root,val);
        if(req == nullptr)
        {
            return nullptr;
        }
        return req;    
    }
};