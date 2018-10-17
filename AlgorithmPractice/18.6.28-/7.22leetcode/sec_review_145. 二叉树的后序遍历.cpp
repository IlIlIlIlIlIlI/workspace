
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> s;
        TreeNode *last = NULL,*top;
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                root = root->left;
            }
            else if(!s.empty())
            {
                top = s.top();
                if(top->right && top->right != last)
                {
                    root = top->right;
                }
                else
                {
                    last = top;
                    vec.push_back(top->val);
                    s.pop();
                }
            }
        }
        return vec;
    }
};
