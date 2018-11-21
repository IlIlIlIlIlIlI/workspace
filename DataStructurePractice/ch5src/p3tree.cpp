#include "p3tree.h"
#include <ctype.h>

/* 线索二叉树的主函数
 */
void biTreTree()
{
	BiThrTree root = NULL, Thrt;
	cout << "按先序次序输入二叉树的结点值（字母，小数点表示空子树）\n"
		 << "例如键盘输入: abc..de.g..f...（书P127图6.8(b)）\n"
		 << "例如键盘输入: abdh..i..e..cf..g..（6树和二叉树C.ppt P10图）\n";
	Create_BiThrTree(root);
	cout << "\n中序遍历尚未线索化的二叉树: ";
	LDR(root);
	InOrderThreading(Thrt, root);
	cout << "\n中序遍历线索化二叉树: ";
	InOrderTraverse_Thr(Thrt);
	cout << "\r\n";
	getchar();
}

/* 二叉树的主函数
 */
void biTree()
{
	BiTree root = NULL;
	cout << "按先序次序输入二叉树的结点值（字母，小数点表示空子树）\n"
		 << "例如键盘输入: abc..de.g..f...（书P127图6.8(b)）\n";
	Create_BiTree(root);
	cout << "叶子结点的个数: " << countOfLeaves(root) << '\n';
	hierachyOf(root);
	cout << "\r\n";
	//LDR(root);
	//inOrder(root); //非递归地中序遍历
	preOrder(root); //非递归地先序遍历
	level(root);	//层次遍历
	DisplayBiTree(root);
	DisplayBiTreeAsList(root);
	DisplayBiTreeAsNested(root);
	getchar();
}

int main()
{
	biTree();
	//biTreTree();
	getchar();
	return 0;
}
