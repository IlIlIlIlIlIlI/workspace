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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> num;
        helper(root,num);
        return num;
    }
private:
    void helper(TreeNode* node, vector<int>& num)
    {
        if(node)
        {
            helper(node->left,num);

            num.push_back(node->val);

            helper(node->right,num);
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> vec;
        while(root || !stk.empty())
        {
            if(root)
            {
                stk.push(root);
                root = root->left;
            }
            else if(!stk.empty())
            {
                vec.push_back(stk.top() -> val);
                root = stk.top() -> right;
                stk.pop();
            }
        }
        return vec;
    }
};
