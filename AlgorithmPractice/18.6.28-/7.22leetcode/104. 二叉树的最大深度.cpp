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
    int maxDepth(TreeNode* root) {
        int left, right;
        if (!root) {
            return 0;
        }else {
            left = maxDepth(root->left);
            right = maxDepth(root->right);
            return left > right ? left + 1 : right + 1;
        }
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

    int maxDepth(TreeNode* root) {
        int maxn = 0;
        if(root != NULL)
        {
            maxn++;
            int maxLeft = maxDepth(root->left);
            int maxRight = maxDepth(root->right);
            maxn += (maxLeft > maxRight) ? maxLeft : maxRight;
        }
        return maxn;
    }
};
