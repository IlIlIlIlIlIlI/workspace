//https://repl.it/@IlIlIlIlIlIlI/SaneRespectfulCensorware

#include "Btree.h"
#include <iostream>
using namespace std;

//    定义树先序创建函数
void initBtree(PTREE &bTree)
{

	//	PTREE bTree = (PTREE)malloc(sizeof(TREE));
	bTree = new TREE;
	bTree->left = NULL;
	bTree->right = NULL;
	bTree->value = 0;
}
//1 3 7 15
void insertNode(Node &Tree, int value)
{

	PTREE p = Tree;
	//  while (p->left != pArr && p->right != pArr) {
	if (value > p->value)
	{
		if (p->right == NULL)
		{
			PTREE pArr = (PTREE)malloc(sizeof(TREE));
			pArr->value = value;
			pArr->left = NULL;
			pArr->right = NULL;
			p->right = pArr;
			//return;
		}
		else
		{
			insertNode(p->right, value); //p = p->right;
		}
	}
	if (value < p->value)
	{
		if (p->left == NULL)
		{
			PTREE pArr = (PTREE)malloc(sizeof(TREE));
			pArr->value = value;
			pArr->left = NULL;
			pArr->right = NULL;
			p->left = pArr;
			//return;
		}
		else
		{
			insertNode(p->left, value);
		}
	}
	//}
	//return;
}

void CreatTree(PTREE &bTree)
{

	int val[100];
	int i = 0;
	int length;

	printf("输入队列，以-99结束: \n");
	scanf("%d", &val[i]);
	while (val[i] != GUARD)
	{
		i++;
		scanf("%d", &val[i]);
	}
	length = i;

	for (i = 0; i < length; i++)
	{
		insertNode(bTree, val[i]);
		printf("前序遍历: ");
		PreOrderTree(bTree);
		printf("\n");
	} //for
}

//    树的前序遍历函数定义
void PreOrderTree(PTREE bTree)
{

	if (bTree == NULL)
		return;
	else
	{
		printf("%d  ", bTree->value);
		PreOrderTree(bTree->left);
		PreOrderTree(bTree->right);
	}
}
//    树的中序遍历函数定义
void InOrderTree(PTREE bTree)
{

	if (bTree == NULL)
		return;
	else
	{
		InOrderTree(bTree->left);
		printf("%d  ", bTree->value);
		InOrderTree(bTree->right);
	}
}

//    树的后序遍历函数定义
void PostOrderTree(PTREE bTree)
{

	if (bTree == NULL)
		return;
	else
	{
		PostOrderTree(bTree->left);
		PostOrderTree(bTree->right);
		printf("%d  ", bTree->value);
	}
}

//    获取树高的函数定义
int GetHeight(PTREE bTree)
{
	int Height = 0;
	if (bTree == NULL)
		return 0;

	//树的高度 = max(左子树的高度，右子树的高度) + 1
	else
	{
		int L_Height = GetHeight(bTree->left);
		int R_Height = GetHeight(bTree->right);
		Height = L_Height >= R_Height ? L_Height + 1 : R_Height + 1;
	}
	return Height;
}

//    打印树的叶子节点函数定义
void LeafOfTree(PTREE bTree)
{
	if (bTree)
	{
		if (!bTree->left && !bTree->right)
		{
			printf("%d  ", bTree->value);
		}
		else
		{
			LeafOfTree(bTree->left);
			LeafOfTree(bTree->right);
		}
	}
}
//    获取树的叶子节点个数函数定义
int GetLeafNum(PTREE bTree)
{
	if (bTree)
	{
		if (!bTree->left && !bTree->right)
		{
			return 1;
		}
		else
		{
			return GetLeafNum(bTree->left) + GetLeafNum(bTree->right);
		}
	}
	else
	{
		return 0;
	}
}

void GetElem(PTREE bTree, int e)
{
	PTREE tmp = bTree;
	stack<PTREE> s;
	PTREE ans = NULL;
	while (tmp || !s.empty())
	{
		if (tmp)
		{
			if (tmp->value == e)
			{
				ans = tmp;
				break;
			}
			s.push(tmp);
			tmp = tmp->left;
		}
		else
		{
			PTREE p = s.top();
			s.pop();
			if (p->right->value == e)
			{
				ans = p;
				break;
			}
			tmp = p->right;
		}
	}
	if (!ans)
	{
		printf("不存在！\n");
	}
	else
	{
		InOrderTree(ans);
	}
}

int nubmerOfNodes(PTREE root)	//计算树的节点总数
{
	if (root == NULL)
	{
		return 0;
	}
	return (1 + nubmerOfNodes(root->left) + nubmerOfNodes(root->right));
}
void bTreetobTree(PTREE &bTree)
{
	PTREE tmp = bTree;
	stack<PTREE> s;
	vector<int> vec; //前序遍历，取出二叉树到left数组
	while (tmp || !s.empty())
	{
		if (tmp)
		{
			vec.push_back(tmp->value);
			s.push(tmp);
			tmp = tmp->left;
		}
		else
		{
			tmp = s.top()->right;
			s.pop();
		}
	}

	sort(vec.begin(), vec.end()); //升序排序

	int sum = nubmerOfNodes(bTree);
	int mid = sum / 2;
	PTREE root = (PTREE)malloc(sizeof(TREE));
	root->value = vec[mid];
	root->left = NULL;
	root->right = NULL;

	queue<PTREE> q;
	q.push(root);
	int l = mid - 1, r = mid + 1;
	while (!q.empty() && ((l >= 0) || (r < vec.size())))
	{
		PTREE now = q.front();
		q.pop();

		if (l >= 0)
		{
			now->left = (PTREE)malloc(sizeof(TREE));
			now->left->value = vec[l];
			q.push(now->left);
			l--;
		}
		else
		{
			now->left = NULL;
		}
		if (r < vec.size())
		{
			now->right = (PTREE)malloc(sizeof(TREE));
			now->right->value = vec[r];
			q.push(now->right);
			r++;
		}
		else
		{
			now->right = NULL;
		}
	}

  cout << "\n中序遍历：\n";
	InOrderTree(root);
}

//    主函数
int main()
{
	int e, choice;
	PTREE tree0;
	initBtree(tree0);
	for (;;)
	{
		printf("\n           二叉数的基本操作 (二叉树排序) \n");
		printf("             1.创建一个二叉树\n");
		printf("             2.前序遍历结果\n");
		printf("             3.中序遍历结果\n");
		printf("             4.后序遍历结果\n");
		printf("             5.二叉树的高度\n");
		printf("             6.打印叶子节点\n");
		printf("             7.查找一个元素，若存在则中序遍历输出该元素对应的子树，若不存在返回空\n");
		printf("             8.将二叉树转化为完全二叉树\n");
		printf("             9.退出系统\n");
		printf("请选择：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			CreatTree(tree0);
			break;
		case 2:
			printf("\n前序遍历结果为：");
			PreOrderTree(tree0);
			break;
		case 3:
			printf("\n中序遍历结果为：");
			InOrderTree(tree0);
			break;
		case 4:
			printf("\n后序遍历结果为：");
			PostOrderTree(tree0);
			break;
		case 5:
			printf("\n二叉树的高度为：%d", GetHeight(tree0));
			break;
		case 6:
		{
			CreatTree(tree0);
			printf("\n叶子节点个数为：%d", GetLeafNum(tree0));
			printf("\n");
			LeafOfTree(tree0);
			bTreetobTree(tree0);
			break;
		}
		case 7:
		{
			CreatTree(tree0);
			printf("输入待查找元素e：");
			scanf("%d", &e);
			GetElem(tree0, e);
			break;
		}
		case 8:
		{
			CreatTree(tree0);
			bTreetobTree(tree0);
			break;
		}
		case 9:
			printf("请退出系统!\n");
			exit(0);
			break;
		}
	}
	return 1;
}
