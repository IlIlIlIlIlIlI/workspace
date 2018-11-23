#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
//using namespace std;

#define Maxsize 100
#define MaxMatrixsize 10
#define GUARD -99

typedef int Elementtype;       //    定义数据类型，可根据需要自行定制
typedef struct TreeNode *Node; //    Node相当于struct treeNode *
//    定义数节点结构
typedef struct TreeNode
{
    Elementtype value;
    Node left;  //    树节点的左子节点
    Node right; //    树节点的右子节点
} TREE, *PTREE;

//    函数声明

void initBtree(PTREE &Tree);             //初始化一个树
void insertNode(Node &bTree, int value); ////插入一个节点
void CreatTree(PTREE &bTree);            //    树的先序创建函数
void PreOrderTree(PTREE bTree);          //    树的前序遍历函数
void InOrderTree(PTREE bTree);           //    树的中序遍历
void PostOrderTree(PTREE bTree);         //    树的后序遍历
void LeafOfTree(PTREE bTree);            //    打印树的叶子节点函数
int GetLeafNum(PTREE bTree);             //    获取树叶子节点个数
int GetHeight(PTREE bTree);              //    获取树的高度
void GetElem(PTREE bTree, int e);        //    查找元素e，若存在则中序遍历输出e对应的子数
int nubmerOfNodes(PTREE root);
void bTreetobTree(PTREE &bTree);         //    把二叉树换成完全二叉树，然后中序遍历输出