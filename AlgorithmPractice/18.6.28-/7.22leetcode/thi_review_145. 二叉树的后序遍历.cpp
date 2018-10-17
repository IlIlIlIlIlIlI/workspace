
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> stk;
        TreeNode *last = NULL,*top;
        while(root || !stk.empty())
        {
            if(root)
            {
                stk.push(root);
                root = root->left;
            }
            else if(!stk.empty())
            {
                top = stk.top();
                if(top->right && top->right != last)
                {
                    root = top->right;
                }
                else
                {
                    last = top;
                    vec.push_back(top->val);
                    stk.pop();
                }
            }
        }
        return vec;
    }
};
