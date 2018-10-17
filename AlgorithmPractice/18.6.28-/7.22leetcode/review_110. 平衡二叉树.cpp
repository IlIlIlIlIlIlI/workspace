
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
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        if(abs(helper(root->left) - helper(root->right)) > 1)
        {
            return false;
        }
        else
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
private:
    int helper(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        else
        {
            return max(helper(node->left), helper(node->right))+1;
        }
    }
};
