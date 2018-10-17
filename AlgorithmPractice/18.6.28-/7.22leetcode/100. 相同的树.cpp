class Solution {
public:
	bool helper(TreeNode* p, TreeNode *q)
	{
		if ((p && !q) || (!p &&q)) return false;
		if (!p && !q) return true;

		if (p->val != q->val) return false;
		else
		{
			if (helper(p->left, q->left) && helper(p->right, q->right)) return true;
			else return false;
		}
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {

		return helper(p, q);
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        if(p == NULL || q == NULL)
        {
            return false;
        }
        if(p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
