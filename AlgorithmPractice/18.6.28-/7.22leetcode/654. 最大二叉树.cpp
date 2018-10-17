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
	TreeNode * build_tree(vector<int>& nums, int left, int right)
	{
		int max_num = 0xffffffff, k;
		if (left == right)
			return NULL;
		for (int i = left; i < right; ++i)
		{
			if (nums[i] > max_num)
			{
				max_num = nums[i];
				k = i;
			}
		}
		TreeNode *root = new TreeNode(max_num);//!********
		root->left = build_tree(nums, left, k);
		root->right = build_tree(nums, k + 1, right);
		return root;
	}
public:
	TreeNode * constructMaximumBinaryTree(vector<int>& nums) {
		return build_tree(nums, 0, nums.size());
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return NULL;
        }
        else if(nums.size() == 1)
        {
            TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->val = nums[0];
            node->left = NULL;
            node->right = NULL;
            return node;
        }
        else
        {
            int arg = 0;
            for(int i = 1;i<nums.size();i++)
            {
                if(nums[i] > nums[arg])
                {
                    arg = i;
                }
            }
            vector<int> n1,n2;
            for(int i = 0;i < arg;i++)
            {
                n1.push_back(nums[i]);
            }
            for(int i = arg+1;i < nums.size();i++)
            {
                n2.push_back(nums[i]);
            }
            TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->val = nums[arg];
            node->left = constructMaximumBinaryTree(n1);
            node->right = constructMaximumBinaryTree(n2);
            return node;
        }
    }
};








#include <iostream>
using namespace std;

struct Point
{
    int x,y;
    Point(int x = 0,int y = 0):x(x),y(y) {}
};

Point operator + (const Point& A,const Point& B)
{
    return Point(A.x+B.x,A.y+B.y);
}

ostream& operator << (ostream &out,const Point& p)
{
    out << "(" << p.x << "," << p.y << ")" << endl;
    return out;
}

template<typename T>
T sum(T* begin, T* end)
{
    T ans = 0;
    for(T *p = begin; p != end; p++)
    {
        ans = ans + *p;
    }
    return ans;
}

int main()
{
    Point a,b(1,2);
    a.x = 3;
    cout << a+b;
}
