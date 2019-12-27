#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; //顶点类型应由用户定义
typedef int EdgeType;	//边上的权值类型应由用户定义
typedef int Boolean;	 //Boolean 是布尔类型，其值是TRUE 或FALSE

#define TRUE 1
#define FALSE 0
#define MAXVEX 100	 //最大顶点数，应由用户定义
#define INFINITY 65535 //用65535来代表无穷大
#define GUARD -99	  //输入的终止符
Boolean visited[MAXVEX];

typedef struct Graph
{
	VertexType vexs[MAXVEX];	  //顶点表
	EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵，可看作边
	int numVertexes, numEdges;	//图中当前的顶点数和边数
} Graph;

//打印图
void printGraph(Graph g)
{
	int i, j;
	for (i = 0; i < g.numVertexes; i++)
	{
		for (j = 0; j < g.numVertexes; j++)
		{
			printf("%d  ", g.arc[i][j]);
		}
		printf("\n");
	}
}

//建立一个youxiang网图的邻接矩阵表示
void CreateGraph(Graph &g)
{
	int i, j, k;
	printf("输入顶点的字符串，以回车结束:\n");
	char a[MAXVEX] = {0};
	int len = 0;
	i = 0;
	scanf("%s", a);
	getchar();
	while (a[i]) //计算输入的数组长度
	{
		g.vexs[i] = a[i];
		++len;
		++i;
	}
	g.numVertexes = len;

	g.numEdges = g.numVertexes * g.numVertexes; //边数初始化为n^2

	for (i = 0; i < g.numVertexes; i++)
	{
		for (j = 0; j < g.numVertexes; j++)
		{
			g.arc[i][j] = INFINITY; //邻接矩阵初始化
		}
	}

	for (i = 0; i < g.numVertexes; i++)
	{
		j = 0;
		printf("输入点v[%d]上各边的权值，以-99结束:\n", i);
		do
		{
			scanf("%d", &k);
			if (k != GUARD)
			{
				g.arc[i][j] = k;
			}
			if (k == 0)
			{
				g.arc[i][j] = INFINITY;
				g.numEdges = g.numEdges - 1;
			}
			j++;
		} while (k != GUARD);
	}

	//输出
	printf("顶点数：%d，边数： %d\n", g.numVertexes, g.numEdges);
	printf("邻接矩阵为：\n");
	printGraph(g);
}

//邻接矩阵的深度优先递归算法
void DFS(Graph g, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", g.vexs[i]); //打印顶点，也可以其他操作
	for (j = 0; j < g.numVertexes; j++)
	{
		if (g.arc[i][j] != INFINITY && !visited[j])
		{
			DFS(g, j); //对为访问的邻接顶点递归调用
		}
	}
}

//邻接矩阵的深度遍历操作
void DFSTraverse(Graph g)
{
	int i;
	for (i = 0; i < g.numVertexes; i++)
	{
		visited[i] = FALSE; //初始化所有顶点状态都是未访问过状态
	}
	for (i = 0; i < g.numVertexes; i++)
	{
		if (!visited[i]) //对未访问的顶点调用DFS
		{
			DFS(g, i);
		}
	}
}

//邻接矩阵的广度遍历操作
void BFSTraverse(Graph g) //类似于树的层次遍历
{
	int i, j;
	LinkQueue q;
	InitQueue(q);
	for (i = 0; i < g.numVertexes; i++)
	{
		visited[i] = FALSE;
	}

	for (i = 0; i < g.numVertexes; i++) //对每个顶点做循环
	{
		if (!visited[i]) //若是未访问过
		{
			visited[i] = TRUE;
			printf("%c ", g.vexs[i]); //打印结点，也可以其他操作
			InQueue(q, i);			  //将此结点入队列
			while (!EmptyQueue(q))	//将队中元素出队列，赋值给
			{
				int n;
				OutQueue(q, n);
				for (j = 0; j < g.numVertexes; j++)
				{
					if (g.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c ", g.vexs[j]);
						InQueue(q, j);
					}
				}
			}
		}
	}
}

/*
typedef struct Graph
{
	VertexType vexs[MAXVEX];        //顶点表
	EdgeType   arc[MAXVEX][MAXVEX]; //邻接矩阵，可看作边
	int numVertexes, numEdges;      //图中当前的顶点数和边数
} Graph;
*/
void Dijkstra(Graph g, int i, int j)
{
	for (int x = 0; x < g.numVertexes; x++)
	{
		int min = INFINITY;
		int v = 0;
		for (int y = 0; y < g.numVertexes; y++)
		{
			if (!visited[y] && g.arc[i][y] < min)
			{
				v = y;
				min = g.arc[i][y];
			}
		}
		visited[v] = TRUE;
		for (int z = 0; z < g.numVertexes; z++)
		{
			if (!visited[z] && (g.arc[i][v] + g.arc[v][z]) < g.arc[i][z])
			{
				g.arc[i][z] = g.arc[i][v] + g.arc[v][z];
			}
		}
	}
	printf("%d\n", g.arc[i][j]);
}
void Floyd(Graph g, int i, int j)
{
	for (int x = 0; x < g.numVertexes; x++)
	{
		for (int y = 0; y < g.numVertexes; y++)
		{
			for (int z = 0; z < g.numVertexes; z++)
			{
				if ((g.arc[y][x] + g.arc[x][z]) < g.arc[y][z])
				{
					g.arc[y][z] = g.arc[y][x] + g.arc[x][z];
				}
			}
		}
	}
	printf("%d\n", g.arc[i][j]);
}

int main(int argc, char **argv)
{
	Graph g;
	int choice;
	for (;;)
	{
		printf("\n           有向图的基本操作  \n");
		printf("             1.创建一个有向图\n");
		printf("             2.输出图\n");
		printf("             3.深度优先遍历图\n");
		printf("             4.广度优先遍历图\n");
		printf("             5.计算最短距离（Dijkstra算法+Floyd算法）\n");
		//printf("             6.计算最短距离（Floyd算法）\n");
		printf("             7.退出系统\n");

		printf("请选择：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			CreateGraph(g);
			break;
		case 2:
			printGraph(g);
			break;
		case 3:
			DFSTraverse(g);
			break;
		case 4:
			BFSTraverse(g);
			break;
		case 5:
			Dijkstra(g, 0, 5);
			Floyd(g, 0, 5);
			break;

		case 7:
			printf("请退出系统!\n");
			exit(0);
			break;
		}
	}
	//邻接矩阵创建图
	CreateGraph(g);
	printGraph(g);
	return 0;
}
