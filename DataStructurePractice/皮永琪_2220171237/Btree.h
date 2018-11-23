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

typedef int Elementtype;       //    �����������ͣ��ɸ�����Ҫ���ж���
typedef struct TreeNode *Node; //    Node�൱��struct treeNode *
//    �������ڵ�ṹ
typedef struct TreeNode
{
    Elementtype value;
    Node left;  //    ���ڵ�����ӽڵ�
    Node right; //    ���ڵ�����ӽڵ�
} TREE, *PTREE;

//    ��������

void initBtree(PTREE &Tree);             //��ʼ��һ����
void insertNode(Node &bTree, int value); ////����һ���ڵ�
void CreatTree(PTREE &bTree);            //    �������򴴽�����
void PreOrderTree(PTREE bTree);          //    ����ǰ���������
void InOrderTree(PTREE bTree);           //    �����������
void PostOrderTree(PTREE bTree);         //    ���ĺ������
void LeafOfTree(PTREE bTree);            //    ��ӡ����Ҷ�ӽڵ㺯��
int GetLeafNum(PTREE bTree);             //    ��ȡ��Ҷ�ӽڵ����
int GetHeight(PTREE bTree);              //    ��ȡ���ĸ߶�
void GetElem(PTREE bTree, int e);        //    ����Ԫ��e��������������������e��Ӧ������
int nubmerOfNodes(PTREE root);
void bTreetobTree(PTREE &bTree);         //    �Ѷ�����������ȫ��������Ȼ������������