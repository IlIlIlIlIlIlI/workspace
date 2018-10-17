/**
��Ŀ�ܼ򵥶����������������
���ݽṹ�Ľ̲��϶�����������ʾ�����롣
��ʵ������������ֽⷨ��

�ݹ�ⷨ(recursive solution)
ջ�����ⷨ(iterative way(stack))
Ī��˹�ⷨ(morris traversal)

���ֽⷨ����ʱ�临�Ӷ�ΪO(n) �ռ临�Ӷ�1��2ΪO(n)��3ΪO(1)��
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
    vector<int> result;//!******************************ȫ�ֱ���������
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
