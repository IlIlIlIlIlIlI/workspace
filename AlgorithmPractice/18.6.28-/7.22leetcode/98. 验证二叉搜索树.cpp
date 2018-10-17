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
        if (!root) {
            return true;
        }
        bool left = true, right = true;
        TreeNode* p;
        if (root->left) {
            p = root->left;
            while(p->right) {
                p = p->right;
            }
            left = p->val < root->val && isValidBST(root->left);
        }
        if (root->right) {
            p = root->right;
            while(p->left) {
                p = p->left;
            }
            right = p->val > root->val && isValidBST(root->right);
        }
        return left&&right;
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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        stack<TreeNode*> st;
        TreeNode* pre = NULL;
        while(root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (pre && pre->val >= root->val) {
                return false;
            }
            pre = root;
            root = root->right;
        }
        return true;
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
