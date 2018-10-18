class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        } 
        int left_height=maxDepth(root->left);
        int right_height=maxDepth(root->right);
        return max(left_height,right_height)+1;
        
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

static const auto speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxn = 0;
        if(root)
        {
            maxn++;
            int maxLeft = maxDepth(root->left);
            int maxRight = maxDepth(root->right);
            maxn += (maxLeft > maxRight) ? maxLeft : maxRight;
        }
        return maxn;
    }
};
