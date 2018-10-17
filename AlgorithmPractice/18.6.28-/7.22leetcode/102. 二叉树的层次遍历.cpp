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
        vector<vector<int>> level_num;
        if(!root) return level_num;
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            vector<int> single_num;
            while(count--){
                p = q.front();
                single_num.push_back(p->val);
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            level_num.push_back(single_num);
        }
        return level_num;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        helper(root, ans, 0);
        return ans;
    }

private:
    void helper(TreeNode* root, vector<vector<int>> &ans, int level) {
        if (ans.size() > level) {
            ans[level].push_back(root->val);
        } else {
            ans.push_back({root->val});
        }
        if (root->left)
        helper(root->left, ans, level+1);
        if (root->right)
        helper(root->right, ans, level+1);
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
        {
            return ans;
        }
        queue<TreeNode*> q;
        TreeNode *p;
        q.push(root);
        while(!q.empty())
        {
            int cnt = q.size();
            vector<int>  single;
            while(cnt--)
            {
                p = q.front();
                single.push_back(p->val);
                q.pop();
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
            }
            ans.push_back(single);
        }
        return ans;
    }
};

