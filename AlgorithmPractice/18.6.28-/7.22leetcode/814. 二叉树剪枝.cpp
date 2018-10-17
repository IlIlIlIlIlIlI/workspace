/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)return NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(!root->left&&!root->right&&root->val==0)return NULL;
        return root;
    }
};





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!has_1(root))
        {
            return NULL;
        }
        else
        {
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            return root;
        }
    }
private:
    bool has_1(TreeNode* node)
    {
        if(node)
        {
            if(node->val)
            {
                return true;
            }
            else
            {
                bool left = has_1(node->left);
                bool right = has_1(node->right);
                return left || right;
            }
        }
        else
        {
            return false;
        }
    }
};
