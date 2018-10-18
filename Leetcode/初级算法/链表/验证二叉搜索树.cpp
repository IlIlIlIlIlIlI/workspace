
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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* root, long mi, long ma)
    {
        if(!root)
        {
            return true;
        }
        if(root->val <= mi|| root->val >= ma)
        {
            return false;
        }
        return helper(root->left, mi, root->val) && helper(root->right, root->val, ma);
    }
};

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
