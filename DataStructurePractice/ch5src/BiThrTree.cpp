#include "p3tree.h"
#include <ctype.h>

BiThrTree pre; //线索化时使用

//*TBD4* 中序遍历二叉树T，将其线索化，Thrt指向头结点
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
		exit(OVERFLOW);
	Thrt->LTag = Link;
	Thrt->RTag = Thread;
	Thrt->lchild = Thrt; //右指针回指
	if (!T)
	{
		Thrt->lchild = Thrt;
	}
	else
	{
		Thrt->lchild = T;
		pre = Thrt;
		InThreading(T); //中序遍历进行线索化
		pre->rchild = Thrt;
		pre->RTag = Thread; //最后一个节点线索化
		Thrt->rchild = pre;
	}
	return OK;
}

/*TBD5* 中序遍历线索化二叉树，Thrt的左指针指向头结点
 *TBD5* 在InOrderThreading(BiThrTree, BiThrTree)执行完后使用。
 *TBD5*/
Status InOrderTraverse_Thr(BiThrTree Thrt)
{
	BiThrTree p = Thrt->lchild; /*p指向根结点*/
	while (p != Thrt)
	{
		while (p->LTag == 0) /*沿左孩子向下*/
		{
			p = p->lchild;
		}
		cout << p->data << " ";				   /*访问其左子树为空的结点*/
		while (p->RTag == 1 && p->rchild != Thrt) /*沿右线索访问后继结点*/
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
	cout << p->data;
	return OK;
}

Status Create_BiThrTree(BiThrTree &rt)
{
	char ch;
	cin >> ch;
	if (ch == '.')
	{
		rt = NULL;
	}
	else
	{
		if (!(rt = (BiThrNode *)malloc(sizeof(BiThrNode))))
			exit(OVERFLOW);
		if (islower(ch))
			ch = toupper(ch);
		rt->data = ch;
		rt->LTag = Link;
		rt->RTag = Link;
		Create_BiThrTree(rt->lchild);
		Create_BiThrTree(rt->rchild);
	};
	return OK;
}

/*
 * 中序遍历没有线索化的二叉树，不能在InOrderThreading(BiThrTree, BiThrTree)
 * 执行完后使用。
 */
void LDR(BiThrTree rt)
{
	if (rt == NULL)
		return;
	LDR(rt->lchild);
	cout << rt->data;
	//cout << rt->LTag << rt->data << rt->RTag;
	LDR(rt->rchild);
}

// 进行中序线索化
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		//前驱线索
		if (!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		//后继线索
		if (!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}
