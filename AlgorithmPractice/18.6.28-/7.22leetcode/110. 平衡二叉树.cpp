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
    bool isBalanced(TreeNode *root) {
        if (checkDepth(root) == -1) return false;
        else return true;
    }
    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        // ��������ƽ��ʱֱ�ӷ���-1
        if (left == -1) return -1;
        int right = checkDepth(root->right);
        // ��������ƽ��ʱֱ�ӷ���-1
        if (right == -1) return -1;
        int diff = abs(left - right);
        // ���������߶�������1ʱ��ƽ�⣬ֱ�ӷ���-1
        if (diff > 1) return -1;
        // ����ֱ�ӷ��������������߶ȼ���1
        else return 1 + max(left, right);
    }
};

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();



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

