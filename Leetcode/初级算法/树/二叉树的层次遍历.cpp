
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int cnt = q.size();
            vector<int> vec;
            while(cnt--)
            {
                TreeNode *tmp = q.front();
                vec.push_back(tmp->val);
                q.pop();
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
