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
private:
    vector<TreeNode*> NodeStack;

    int copyNode(TreeNode *A, TreeNode *B){//A=B
        A->val = B->val;
        A->left = B->left;
        A->right = B->right;

        return 0;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        TreeNode *workNode = new TreeNode(0);
        if (root != nullptr) copyNode(workNode, root);
        else{
            delete workNode;
            workNode = nullptr;
        }

        while (workNode != nullptr){
            if (workNode->left != nullptr){
                NodeStack.push_back(new TreeNode(0));
                copyNode(NodeStack.back(), workNode);

                copyNode(workNode, NodeStack.back()->left);

                NodeStack.back()->left = nullptr;
                continue;
            }
            if (workNode->right != nullptr){
                NodeStack.push_back(new TreeNode(0));
                copyNode(NodeStack.back(), workNode);

                copyNode(workNode, NodeStack.back()->right);

                NodeStack.back()->right = nullptr;
                continue;
            }

            result.push_back(workNode->val);

            if (NodeStack.empty()){
                delete workNode;
                workNode = nullptr;
            }
            else{
                copyNode(workNode, NodeStack.back());
                delete NodeStack.back();
                NodeStack.pop_back();
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        helper(root,vec);
        return vec;
    }
private:
    void helper(TreeNode* node, vector<int>& vec)
    {
        if(node)
        {
            helper(node->left,vec);
            helper(node->right,vec);
            vec.push_back(node->val);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> stk;
        TreeNode *last = NULL;
        while(root || !stk.empty())
        {
            if(root)
            {
                stk.push(root);
                root = root->left;
            }
            else if(!stk.empty())
            {
                TreeNode *top = stk.top();
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
