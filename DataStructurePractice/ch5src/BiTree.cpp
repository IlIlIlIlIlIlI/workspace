#include "p3tree.h"
#include <ctype.h>
#include <string.h>

BTWithLevel que[MAX_TREE_SIZE];
int front = 0, rear = 0;
BiTree stack[MAX_TREE_SIZE];
int top = 0;

/*TBD1* 根据按先序次序输入二叉树的结点值（字母，小数点表示空子树）创建二叉树rt
 *TBD1* 例如键盘输入: abc..de.g..f..., 创建的二叉树如书P127图6.8(b)所示
 *TBD1*/
Status Create_BiTree(BiTree &rt)
{
	char ch;
	cin >> ch;
	if (ch == '.')
	{
		rt = NULL;
	}
	else
	{
		if (!(rt = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		if (islower(ch))
			ch = toupper(ch);
		rt->data = ch;
		Create_BiTree(rt->lchild);
		Create_BiTree(rt->rchild);
	}
	return OK;
}

//*TBD2* 非递归的先序遍历(题集P42 6.37)
void preOrder(BiTree rt)
{
	BiTree p;
	cout << "先序遍历: ";
	p = rt;
	while (p || !StackEmpty())
	{ //p非空或栈非空
		//1.沿根节点向下，所遍历的内部结点入栈，直至左子树为空的结点
		if (p)
		{
			//2.访问该结点
			cout << p->data;
			Push(p);
			p = p->lchild;
		}
		else
		{
			//3.访问该结点右子树的根，重复步1
			p = p->rchild;
			Pop(p);
		}
	}
	cout << "\r\n";
}

//*TBD3* 层次遍历(题集P42 6.47)
// 注意hierachyOf(BiTree)和hierachyOf1(BiTree)的遍历思路与此题相同
void level(BiTree rt)
{
	if (!rt)
	{
		return;
	}
	queue<BiTree> q;
	q.push(rt);
	int level = 0;
	while (!q.empty())
	{
		cout << "第" << ++level << "层的节点：\n";
		int cnt = q.size();
		while (cnt--)
		{
			BiTree tmp = q.front();
			cout << tmp->data << " ";
			q.pop();
			if (tmp->lchild)
			{
				q.push(tmp->lchild);
			}
			if (tmp->rchild)
			{
				q.push(tmp->rchild);
			}
		}
	}
}

// 递归计算叶子结点数目(题集P42 6.42)
int countOfLeaves(BiTree rt)
{
	if (rt == NULL)
		return 0;
	if ((rt->lchild == NULL) && (rt->rchild == NULL))
		return 1;
	else
		return (countOfLeaves(rt->lchild) + countOfLeaves(rt->rchild));
}

// 递归地中序遍历
void LDR(BiTree rt)
{
	if (rt)
	{
		LDR(rt->lchild);
		cout << rt->data;
		LDR(rt->rchild);
	}
}

// 非递归的中序遍历
void inOrder(BiTree rt)
{
	BiTree p;
	cout << "中序遍历: \n";
	p = rt;
	while (p || !StackEmpty())
	{ //p非空或栈非空
		//1.沿左分支向下，所遍历的内部结点入栈，直至左子树为空的结点
		if (p)
		{
			Push(p);
			p = p->lchild;
		}
		else
		{
			//2.访问该结点(p==NULL)
			Pop(p);
			cout << p->data;
			//3.访问该结点右子树的根，重复步1
			p = p->rchild;
		}
	}
	cout << "\r\n";
}

// 在屏幕上显示二叉树root的结构示意图
void hierachyOf(BiTree root)
{
	int tab, max_leaves, max_width;
	BTWithLevel rt, last;
	BiTree bnode;
	char *padding0, *padding1;
	if (root == NULL)
		return;

	// 根结点入队
	rt = (BTNodeWithLevel *)malloc(sizeof(BTNodeWithLevel));
	last = rt;
	rt->node = root;
	rt->level = 1;
	rt->parentTag = ' ';
	EnQueue(rt);
	cout << "\n二叉树的结构示意图:\n";

	// 按照满二叉树来估计树的显示大小
	max_leaves = 16;						//2^(MAX_TREE_LEVEL - 1); // 计算满二叉树的叶子结点数
	max_width = (max_leaves + 1) * PADDING; // 显示满二叉树叶子结点时所需的字符宽度
	tab = max_width / 2;					// 显示根结点时所需的字符宽度

	// 初始化用于存放补齐字符、结点或边的字符串
	padding0 = (char *)malloc(max_width);
	memset(padding0, 0, max_width);
	padding1 = (char *)malloc(max_width);
	memset(padding1, 0, max_width);

	while (!QueueEmpty())
	{ //按层访问二叉树的结点
		DeQueue(rt);
		bnode = rt->node;

		if ((last == rt) || (rt->level > last->level))
		{
			if (strlen(padding1))
			{
				cout << '\n'
					 << padding0 << '\n'
					 << padding1;
				tab = strlen(padding1) - 2 * PADDING;
			}
			memset(padding0, 0, max_width);
			memset(padding0, ' ', tab);
			memset(padding1, 0, max_width);
			memset(padding1, ' ', tab);
			last = rt;
		}

		// 当前结点的左子树为空，补齐
		/*if ((bnode==NULL)&&(last->parentTag=='/')) {
			memset(&padding0[strlen(padding0)], ' ', PADDING);
			memset(&padding1[strlen(padding1)], ' ', PADDING);
		}*/

		if ((bnode != NULL) && (rt->level == last->level))
		{
			padding0[strlen(padding0)] = rt->parentTag;
			memset(&padding0[strlen(padding0)], ' ', PADDING);
			padding1[strlen(padding1)] = bnode->data;
			memset(&padding1[strlen(padding1)], ' ', PADDING);

			rt = (BTNodeWithLevel *)malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->lchild;
			rt->level = last->level + 1;
			rt->parentTag = '/';
			EnQueue(rt);
			rt = (BTNodeWithLevel *)malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->rchild;
			rt->level = last->level + 1;
			rt->parentTag = '\\';
			EnQueue(rt);
		}
	}
}

void hierachyOf1(BiTree root)
{
	int size = 0, tab;
	BTWithLevel rt, last;
	BiTree bnode;
	char *padding;
	if (root == NULL)
		return;
	rt = (BTNodeWithLevel *)malloc(sizeof(BTNodeWithLevel));
	last = rt;
	rt->node = root;
	rt->level = 1;
	EnQueue(rt);
	cout << endl;
	size = countOfLeaves(root) * 5 * sizeof(char) + 4 * MAX_TREE_LEVEL;
	padding = (char *)malloc(size);
	memset(padding, 0, size);
	tab = (size / 2 - (rt->level) * 3) > 0 ? size / 2 - (rt->level) * 3 : 0;
	while (!QueueEmpty())
	{
		DeQueue(rt);
		bnode = rt->node;
		if ((last == rt) || (rt->level > last->level))
		{
			if (strlen(padding))
			{
				cout << '\n'
					 << padding << '\n';
				tab = strlen(padding) - 8;
			}
			memset(padding, 0, size);
			memset(padding, ' ', tab);
			last = rt;
		}

		if ((bnode != NULL) && (rt->level == last->level))
		{
			padding[strlen(padding)] = (bnode != NULL) ? bnode->data : ' ';
			memset(&padding[strlen(padding)], ' ', 4);
			rt = (BTNodeWithLevel *)malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->lchild;
			rt->level = last->level + 1;
			EnQueue(rt);
			rt = (BTNodeWithLevel *)malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->rchild;
			rt->level = last->level + 1;
			EnQueue(rt);
		}
	}
}

/*
 * 队列的顺序存储实现
 */
bool QueueEmpty()
{
	return (front == rear);
}

void EnQueue(BTWithLevel n)
{
	que[rear] = n;
	rear = (rear + 1) % MAX_TREE_SIZE;
}

void DeQueue(BTWithLevel &n)
{
	n = que[front];
	front = (front + 1) % MAX_TREE_SIZE;
}

/*
 * 堆栈的顺序存储实现
 */
bool StackEmpty()
{
	return (top == 0);
}

void Push(BiTree n)
{
	stack[top] = n;
	if (top++ > MAX_TREE_SIZE)
	{
		cout << "\nStack overflow! exceed MAX_TREE_SIZE.\n";
		exit(OVERFLOW);
	}
}

void Pop(BiTree &n)
{
	if (StackEmpty())
		cout << "\nStack is empty!\n";
	else
	{
		top--;
		n = stack[top];
	}
}

/*
void DisplayBiTree(BiTree rt)的实现
以树的形态"图形化"显示；
*/
int height(BiTree rt)
{
	if(!rt)
	{
		return 0;
	}
	else
	{
		int l = height(rt->lchild);
		int r = height(rt->rchild);
		return (l > r ? l : r) + 1;
	}
}
void DisplayBiTree(BiTree rt)
{
	//hierachyOf(rt);
	/**
	 * 对于第k层（从上往下数，根节点为第一层）
	 * 第一个节点距离起始输出位置为2^（h-k）—1
	 * 节点之间的间隙为2^(h-k+1) —1
	 */
	int h = height(rt), level = 0, ff = 1;
	queue<BiTree> q;
	q.push(rt);
	while (!q.empty())
	{
		level++;
		int cnt = q.size(), f = 0;

		while (cnt--)
		{
			if(!f)
			{
				for(int x = 0; x < pow(2, h-level)-1; x++)
				{
					cout << ' ';
				}
				f = 1;
			}
			else
			{
				for(int x = 0; x < pow(2, h - level + 1) - 1; x++)
				{
					cout << ' ';
				}
			}
			BiTree tmp = q.front();
			cout << tmp->data << " ";
			q.pop();
			if (tmp->lchild)
			{
				q.push(tmp->lchild);
			}
			if (tmp->rchild)
			{
				q.push(tmp->rchild);
			}
			cout << '\n';
		}
	}
}

/*
void DisplayBiTreeAsList(BiTree rt)的实现
广义表的形式显示，即字符串形式显示，如A(B(C,D(E(,G),F)),)
*/
void DisplayBiTreeAsList(BiTree rt)
{
	if (rt)
	{
		cout << rt->data;
		;
		if (rt->lchild && rt->rchild)
		{
			cout << "(";
			DisplayBiTreeAsList(rt->lchild);
			if (rt->rchild)
			{
				cout << ",";
			}
			DisplayBiTreeAsList(rt->rchild);
			cout << ")";
		}
	}
}

/*
void DisplayBiTreeAsNested(BiTree rt)的实现
把嵌套完全展开的方式显示，即像编写代码的缩进格式一样，如：
A
---B
------C
---------
---------
------D
---------E
------------
------------G
---------F
---
*/
void helper(BiTree rt, int tab) //先序遍历
{
	for (int i = 0; i < tab; i++)
	{
		cout << "---";
	}
	if (rt)
	{
		cout << rt->data;
	}
	helper(rt->lchild, tab + 1);
	helper(rt->lchild, tab + 1);
}
void DisplayBiTreeAsNested(BiTree rt)
{
	helper(rt, 0);
}
