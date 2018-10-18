
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
private:
    TreeNode* helper(vector<int>& vec, int l, int r)
    {
        if(l > r)
        {
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = helper(vec, l, mid-1);
        root->right = helper(vec, mid+1, r);
        return root;
    }
};
