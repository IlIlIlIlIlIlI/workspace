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
    int minDepth(TreeNode* root) {
        if(root == NULL )
            return 0;
        if(root->left == NULL )
            return minDepth(root->right)+1;
        else if(root->right == NULL)
            return minDepth(root->left)+1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
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
    int minDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            return 1;
        }
        int left,right;
        if(root->left)
        {
            left = minDepth(root->left);
        }
        else
        {
            left = 0xffffff;
        }
        if(root->right)
        {
            right = minDepth(root->right);
        }
        else
        {
            right = 0xffffff;
        }
        return left < right ? left+1 : right+1;
    }
};
