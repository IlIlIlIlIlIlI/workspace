/**
题目很简单二叉树的中序遍历，
数据结构的教材上都会有这样的示例代码。
其实中序遍历有三种解法：

递归解法(recursive solution)
栈迭代解法(iterative way(stack))
莫里斯解法(morris traversal)

三种解法都是时间复杂度为O(n) 空间复杂度1和2为O(n)，3为O(1)。
*/
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
    vector<int> result;//!******************************全局变量！！！
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
    void inorder(TreeNode* root){
        if(root)
        {
            inorder(root->left);
            result.push_back(root->val);
            inorder(root->right);
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
        vector<int> ans;
        myInorderTraversal(root,ans);
        return ans;
    }
private:
    void myInorderTraversal(TreeNode* node, vector<int>& tmp)
    {
        if(node)
        {
            myInorderTraversal(node->left,tmp);
            tmp.push_back(node->val);
            myInorderTraversal(node->right,tmp);
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
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *tmp = root;
        while(tmp || !stk.empty())
        {
            if(tmp)
            {
                stk.push(tmp);
                tmp = tmp->left;
            }
            else if(!stk.empty())
            {
                ans.push_back(stk.top() -> val);
                tmp = stk.top() -> right;
                stk.pop();
            }
        }
        return ans;
    }
};
