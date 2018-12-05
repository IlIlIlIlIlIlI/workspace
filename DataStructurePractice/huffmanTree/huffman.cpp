#include "huffman.h"
using namespace std;

HuffmanTree HT;
HuffmanCode HC;
int i, n, num;
float *w, wei;
int ans[1024] = {0};

//选择两个parent�?0，且weight最小的结点s1和s2的方法实�?
//n 为叶子结点的总数，s1�? s2两个指针参数指向要选取出来的两�?权值最小的结点
void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2)
{
	//标�?? i
	int i = 0;
	//记录最小权�?
	int min;
	//遍历全部结点，找出单节点
	for (i = 1; i <= n; i++)
	{
		//如果此结点的父亲没有，那么把结点号赋值给 min，跳出循�?
		if ((*huffmanTree)[i].parent == 0)
		{
			min = i;
			break;
		}
	}
	//继续遍历全部结点，找出权值最小的单节�?
	for (i = 1; i <= n; i++)
	{
		//如果此结点的父亲为空，则进入 if
		if ((*huffmanTree)[i].parent == 0)
		{
			//如果此结点的权值比 min 结点的权值小，那么更�? min 结点，否则就�?最开始的 min
			if ((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
			{
				min = i;
			}
		}
	}
	//找到了最小权值的结点，s1指向
	*s1 = min;
	//遍历全部结点
	for (i = 1; i <= n; i++)
	{
		//找出下一�?单节点，且没有�?? s1指向，那么i 赋值给 min，跳出循�?
		if ((*huffmanTree)[i].parent == 0 && i != (*s1))
		{
			min = i;
			break;
		}
	}
	//继续遍历全部结点，找到权值最小的那一�?
	for (i = 1; i <= n; i++)
	{
		if ((*huffmanTree)[i].parent == 0 && i != (*s1))
		{
			//如果此结点的权值比 min 结点的权值小，那么更�? min 结点，否则就�?最开始的 min
			if ((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
			{
				min = i;
			}
		}
	}
	//s2指针指向�?二个权值最小的叶子结点
	*s2 = min;
}

//创建哈夫曼树并求哈夫曼编码的算法如下，w数组存放已知的n�?权�?
void createHuffmanTree(HuffmanTree *huffmanTree, float w[], int n)
{
	//m 为哈�?曼树总共的结点数，n 为叶子结点数
	int m = 2 * n - 1;
	//s1 �? s2 为两�?当前结点里，要选取的最小权值的结点
	int s1;
	int s2;
	//标�??
	int i;
	// 创建哈夫曼树的结点所需的空间，m+1，代表其�?包含一�?头结�?
	*huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));
	//1--n号存放叶子结点，初�?�化叶子结点，结构数组来初�?�化每个叶子结点，初始的时候看做一�?�?单个结点的二叉树
	for (i = 1; i <= n; i++)
	{

		//其中叶子结点的权值是 w【n】数组来保存
		(*huffmanTree)[i].weight = w[i];
		//初�?�化叶子结点（单�?结点二叉树）的�?�子和双亲，单个结点，也就是没有孩子和双亲，==0
		(*huffmanTree)[i].lChild = 0;
		(*huffmanTree)[i].parent = 0;
		(*huffmanTree)[i].rChild = 0;
	} // end of for
	//非叶子结点的初�?�化
	for (i = n + 1; i <= m; i++)
	{
		(*huffmanTree)[i].weight = 0;
		(*huffmanTree)[i].lChild = 0;
		(*huffmanTree)[i].parent = 0;
		(*huffmanTree)[i].rChild = 0;
	}

	printf("\n HuffmanTree: \n");
	//创建非叶子结点，建哈�?曼树
	for (i = n + 1; i <= m; i++)
	{
		select(HuffmanTree, i - 1, &s1, &s2);

		(*HuffmanTree)[s1].parent = i;
		(*HuffmanTree)[s2].parent = i;
		(*HuffmanTree)[i].lChild = s1;
		(*HuffmanTree)[i].lChild = s2;

		(*HuffmanTree)[i].weight = (*HuffmanTree)[s1].weight + (*HuffmanTree)[s2].weight;

		printf("%f (%f, %f)\n", (*huffmanTree)[i].weight, (*huffmanTree)[s1].weight, (*huffmanTree)[s2].weight);
	}

	printf("\n");
}

//哈夫曼树建立完毕，从 n �?叶子结点到根，逆向求每�?叶子结点对应的哈�?曼编�?
void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n)
{
	//指示biaoji
	int i;
	//编码的起始指�?
	int start;
	//指向当前结点的父节点
	int p;
	//遍历 n �?叶子结点的指示标�? c
	unsigned int c;
	//分配n�?编码的头指针
	huffmanCode = (HuffmanCode *)malloc((n + 1) * sizeof(char *));
	//分配求当前编码的工作空间
	char *cd = (char *)malloc(n * sizeof(char));
	//从右向左逐位存放编码，�?�先存放编码结束�?
	cd[n - 1] = '\0';
	//求n�?叶子结点对应的哈�?曼编�?
	for (i = 1; i <= n; i++)
	{
		//初�?�化编码起�?�指�?
		start = n - 1;
		//从叶子到根结点求编码
		for (c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent)
		{
			if ((*huffmanTree)[p].lChild == c)
			{
				//从右到左的顺序编码入数组�?
				cd[--start] = '0'; //左分�?�?0
			}
			else
			{
				cd[--start] = '1'; //右分�?�?1
			}
		} // end of for
		//为�?�i�?编码分配空间
		huffmanCode[i] = (char *)malloc((n - start) * sizeof(char));

		strcpy(huffmanCode[i], &cd[start]);
	}

	free(cd);
	//打印编码序列
	for (i = 1; i <= n; i++)
	{
		printf("HuffmanCode of %d is %s\n", i, huffmanCode[i]);
	}

	printf("\n");
}

/*HuffmanTree HT;
HuffmanCode HC;
int i, n;
float *w, wei;*/
void dataToHuffmanCode(char Huffman[], int data[])
{
	printf("\n 需要创建的文件有�?�少�?码元 = ");
	scanf("%d", &n);
	w = (float *)malloc((n + 1) * sizeof(float));
	printf("\ninput the %d element's weight:\n", n);
	for (i = 1; i <= n; i++)
	{
		printf("%d: ", i);
		fflush(stdin);
		scanf("%f", &wei);
		w[i] = wei;
	}
	createHuffmanTree(&HT, w, n);

	//指示biaoji
	int i;
	//编码的起始指�?
	int start;
	//指向当前结点的父节点
	int p;
	//遍历 n �?叶子结点的指示标�? c
	unsigned int c;
	//分配n�?编码的头指针
	HuffmanCode *huffmanCode = (HuffmanCode *)malloc((n + 1) * sizeof(char *));
	//分配求当前编码的工作空间
	char *cd = (char *)malloc(n * sizeof(char));
	//从右向左逐位存放编码，�?�先存放编码结束�?
	cd[n - 1] = '\0';
	//求n�?叶子结点对应的哈�?曼编�?
	for (i = 1; i <= n; i++)
	{
		//初�?�化编码起�?�指�?
		start = n - 1;
		//从叶子到根结点求编码
		for (c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent)
		{
			if ((*huffmanTree)[p].lChild == c)
			{
				//从右到左的顺序编码入数组�?
				cd[--start] = '0'; //左分�?�?0
			}
			else
			{
				cd[--start] = '1'; //右分�?�?1
			}
		} // end of for
		//为�?�i�?编码分配空间
		huffmanCode[i] = (char *)malloc((n - start) * sizeof(char));

		strcpy(huffmanCode[i], &cd[start]);
	}

	free(cd);
	//打印编码序列
	for (i = 0; i < num; i++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (huffmanCode[i] == data[i])
			{
				strcat(Huffman, &huffmanCode[i]);
				break;
			}
		}
	}
}

void HuffmanCodeTodata(char Huffman, int &data)
{
	printf("请输入需要读取的文件名：");
	char fileName[20];
	int i = 0;
	while (~scanf("%c", &fileName[i]))
	{
		i++;
	}

	FILE *fp = fopen(fileName, "r");
	if (!fp)
	{
		return;
	}

	char ch = getc(fp);
	stack<char> num;
	stack<stack<char>> nums while (ch != EOF)
	{
		if (ch != ' ' && ch != EOF)
		{
			num.push(ch);
		}
		else
		{
			nums.push(num);
			num = stack<char>();
		}
		ch = getc(fp);
	}
	fclose(fp);

	i = 0;
	int sum = 0;
	while (!nums.empty())
	{
		int tmp = 0, ten = 1;
		while (!nums[i].empty)
		{
			tmp += ((nums[i].top() - '0') * ten);
			ten *= 10;
			nums[i].pop();
		}
		ans[tmp]++;
		sum++;
	} //全局变量 int ans[1024];
	//sum为数字的总数
	
	int n = 0;
	for(i = 0; i < 1024; i++)
	{
		if(ans[i])
		{
			n++;
		}
	}

	//*****************************************
	//m 为哈�?曼树总共的结点数，n 为叶子结点数
	int m = 2 * n - 1;
	//s1 �? s2 为两�?当前结点里，要选取的最小权值的结点
	int s1;
	int s2;
	//标�??
	// 创建哈夫曼树的结点所需的空间，m+1，代表其�?包含一�?头结�?
	HuffmanTree *huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));
	//1--n号存放叶子结点，初�?�化叶子结点，结构数组来初�?�化每个叶子结点，初始的时候看做一�?�?单个结点的二叉树
	for (i = 1; i < 1024; i++)
	{
		if(ans[i])
		{				
			//其中叶子结点的权值是 w【n】数组来保存
			(*huffmanTree)[i].weight = w[i];
			//初�?�化叶子结点（单�?结点二叉树）的�?�子和双亲，单个结点，也就是没有孩子和双亲，==0
			(*huffmanTree)[i].lChild = 0;
			(*huffmanTree)[i].parent = 0;
			(*huffmanTree)[i].rChild = 0;
		}
	} // end of for
	//非叶子结点的初�?�化
	for (i = n + 1; i <= m; i++)
	{
		(*huffmanTree)[i].weight = 0;
		(*huffmanTree)[i].lChild = 0;
		(*huffmanTree)[i].parent = 0;
		(*huffmanTree)[i].rChild = 0;
	}

	printf("\n HuffmanTree: \n");
	//创建非叶子结点，建哈�?曼树
	for (i = n + 1; i <= m; i++)
	{
		select(HuffmanTree, i - 1, &s1, &s2);

		(*HuffmanTree)[s1].parent = i;
		(*HuffmanTree)[s2].parent = i;
		(*HuffmanTree)[i].lChild = s1;
		(*HuffmanTree)[i].lChild = s2;

		(*HuffmanTree)[i].weight = (*HuffmanTree)[s1].weight + (*HuffmanTree)[s2].weight;

		//printf("%f (%f, %f)\n", (*huffmanTree)[i].weight, (*huffmanTree)[s1].weight, (*huffmanTree)[s2].weight);
	}
	//****************************************************

	for (i = 0; i < 1024; i++)
	{
		if (ans[i])
		{
		}
	}
}

int main()
{
	int choice;
	for (;;)
	{
		printf("\n           哈夫曼编�? \n");
		printf("             1.哈夫曼编码实现\n");
		printf("             2.输入一串数�?，编译成哈夫曼编码\n");
		printf("             3.将一串哈�?曼编码，还原成原来的数据\n");
		//	printf("             4.输入一�?文本，统计文�?�?各字符串的数�?，�?�算相应的权重，使用该权重构建哈�?曼编码，使用该编码编译原文件\n");
		printf("             5.退出系统\n");
		printf("请选择�?");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			printf("\n 需要创建的文件有�?�少�?码元 = ");
			scanf("%d", &n);
			w = (float *)malloc((n + 1) * sizeof(float));
			printf("\ninput the %d element's weight:\n", n);
			for (i = 1; i <= n; i++)
			{
				printf("%d: ", i);
				fflush(stdin);
				scanf("%f", &wei);
				w[i] = wei;
			}
			createHuffmanTree(&HT, w, n);
			creatHuffmanCode(&HT, &HC, n);
			break;
		}
		case 2:
		{
			printf("\n输入数据�?数为�?");

			scanf("%d", &num);

			printf("\n输入数据为：");
			int data[num];
			for (i = 0; i < num; i++)
			{
				printf("data[%d]: ", i);
				scanf("%d", &data[i]);
			}
			char Huffman[5 * num] = "";
			dataToHuffmanCode(Huffman, data);
			puts(Huffman);
			break;
		}
		case 3:
		{
			printf("\n输入的哈�?曼编码为�?");

			break;
		}
		case 4:
		{
			printf("请退出系�?!\n");
			exit(0);
			break;
		}
		}
	}
	return 1;
}
