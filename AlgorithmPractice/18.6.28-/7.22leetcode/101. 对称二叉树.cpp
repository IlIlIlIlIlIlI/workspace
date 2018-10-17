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
    bool isSymmetric(TreeNode* root) {

     stack<TreeNode*> leftStack;
     stack<TreeNode*> rightStack;
     if(root==NULL)  return true;
     if(root->left==NULL&&root->right==NULL) return true;
     if(root->left==NULL||root->right==NULL) return false;

     TreeNode* leftNodes=root->left;
     TreeNode* rightNodes=root->right;
     while(leftNodes!=NULL)
     {
         if(rightNodes==NULL) return false;
         if(leftNodes->val!=rightNodes->val) return false;
         if(leftNodes->left!=NULL)
         {
             if(rightNodes->right==NULL) return false;

             leftStack.push(leftNodes);
             leftNodes=leftNodes->left;

             rightStack.push(rightNodes);
             rightNodes=rightNodes->right;


         }
         else
         {
             if(rightNodes->right!=NULL) return false;

             leftNodes=leftNodes->right;
             rightNodes=rightNodes->left;
             if(leftNodes==NULL)
             {
                 if(rightNodes!=NULL) return false;

                 while(!leftStack.empty())
                {
                    leftNodes=leftStack.top();
                    leftStack.pop();

                    rightNodes=rightStack.top();
                    rightStack.pop();

                    if(leftNodes->right!=NULL)
                    {
                        if(rightNodes->left==NULL) return false;
                        leftNodes=leftNodes->right;
                        rightNodes=rightNodes->left;
                        break;
                    }
                    else
                    {
                       if(rightNodes->left!=NULL) return false;
                       leftNodes=NULL;
                       rightNodes=NULL;
                    }
                }
             }


         }

     }
        return true;

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
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
        {
            return true;
        }
        if((l && !r) || (!l && r) || (l->val != r->val))
        {
            return false;
        }
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
};
