#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <string.h>
//haffman 树的结构

typedef struct
{
	//叶子结点权值
	float weight;
	//指向双亲，和孩子结点的指针
	unsigned int parent;
	unsigned int lChild;
	unsigned int rChild;
} Node, *HuffmanTree;

//动态分配数组，存储哈夫曼编码
typedef char *HuffmanCode;

void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2);
void createHuffmanTree(HuffmanTree *huffmanTree, float w[], int n);
void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n);
void dataToHuffmanCode(char &Huffman, int data[]);
void HuffmanCodeTodata(char Huffman, int &data);