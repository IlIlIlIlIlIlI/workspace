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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p=root;
        vector<int> result;
        while(p!=NULL||!s.empty())
        {
            while(p!=NULL)
            {
                s.push(p);
                result.push_back(p->val);
                p=p->left;
            }
            if(!s.empty())
            {
                p=s.top();
                s.pop();
                p=p->right;
            }
        }
        return result;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        helper(root,vec);
        return vec;
    }
private:
    void helper(TreeNode* node, vector<int>& vec)
    {
        if(node)
        {
            vec.push_back(node->val);
            helper(node->left,vec);
            helper(node->right,vec);
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
            if(root)
            {
                stk.push(root);
                vec.push_back(root->val);
                root = root->left;
            }
            else if(!stk.empty())
            {
                root = stk.top() -> right;
                stk.pop();

            }
        }
        return vec;
    }
};
