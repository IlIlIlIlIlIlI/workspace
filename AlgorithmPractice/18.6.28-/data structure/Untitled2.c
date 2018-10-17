#include<stdio.h>
#include<stdlib.h>
#define M 3
#define random(x) (rand()%x)
typedef struct nodeList
{
	int id;
	char name[20];
	int class;
	char major[50];
	int score[M];
	struct nodeList *next;
}List;

List *list;

void allShow()
{
    List *tem = list;
    while(tem != NULL)
    {
        printf("%d\t%s\t\t%d\t%-10s\t",tem->id,tem->name,tem->class,tem->major);
        for(int i = 0;i<M;i++)
        {
            printf("%d ",tem->score[i]);
        }
        tem = tem->next;
        printf("\n");
    }
}

void show(List *tem)
{
    printf("%d\t%s\t\t%d\t%s\t",tem->id,tem->name,tem->class,tem->major);
    for(int i = 0;i<M;i++)
    {
        printf("%d ",tem->score[i]);
    }
}

List* reverse(List *head)
{
    //递归终止条件：找到链表最后一个结点
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        List *newhead = reverse(head->next);//先反转后面的链表，从最后面的两个结点开始反转，依次向前
        head->next->next = head;//将后一个链表结点指向前一个结点
        head->next = NULL;//将原链表中前一个结点指向后一个结点的指向关系断开
        return newhead;
    }
}

void CreateList()
{
	int n;
	printf("请输入您要录入的学生数：\n");
	scanf("%d",&n);
	List *tem = list;
    while(tem != NULL)
    {
        if(tem->next == NULL)
        {
            break;
        }
        tem = tem->next;
    }
    for(int i = 0;i<n;i++)
        {
            List *new = (List*)malloc(sizeof(list));
            printf("正在录入第%d个学生的信息！\n",i+1);
            printf("请输入学号：");
            scanf("%d",&(new->id));
            printf("请输入姓名：");
            scanf("%s",new->name);
            printf("请输入班级：");
            scanf("%d",&(new->class));
            printf("请输入专业：");
            scanf("%s",new->major);
            printf("请输入%d项成绩\n",M);
            for(int j = 0;j<M;j++)
            {
                scanf("%d",&(new->score[j]));
            }
            new->next = NULL;
            tem->next = new;
            tem = tem->next;
        }
	list = reverse(list);
	Save(list);
}

void Output(int id)
{
    List *tem = list;
    while(tem != NULL)
    {
        if(tem->id == id)
        {
            show(tem);
            break;
        }
        tem = tem->next;
    }
    printf("\n");
}

void Save(List *p)
{
	printf("请问是否要存入文件？\n");
	printf("1 ---- 是	2 ---- 否\n");
	int ok;
	scanf("%d",&ok);
    if(ok == 1)
    {
        char fileName[50];
        printf("请输入存入的文件名\n");
        scanf("%s",fileName);
        FILE *fp;
        if((fp = fopen(fileName,"wb")) == NULL)
        {
            printf("OPEN FILE ERROR!\n");
            return;
        }
        List *tem = p;
        while(tem != NULL)
        {
            printf("%d\n",tem->id);
            printf("hahahahahahaha\n");
            fprintf(fp,"%d\t%s\t\t%d\t%-10s\t",tem->id,tem->name,tem->class,tem->major);
            for(int i = 0;i<M;i++)
            {
                fprintf(fp,"%d ",tem->score[i]);
            }
            fprintf(fp,"\n");
            tem = tem->next;
        }
        printf("KKKKKKKKKKKKKKKKK\n");
        printf("保存成功！\n");
    }
    else if(ok == 2)
    {
        return;
    }
}

void Fetch()
{
    char fileName[50];
    printf("请输入读取的文件名\n");
    scanf("%s",fileName);
    FILE *fp;
    if((fp = fopen(fileName,"rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }

    List *tem = (List*)malloc(sizeof(List));	//存入指针
    fseek(fp,random(100)*sizeof(List),0);
    fread(tem,sizeof(List),1,fp);

	printf("%d\t%s\t%d\t%s\n",tem->id,tem->name,tem->class,tem->major);
}

List* Search_num(int num)
{
    char fileName[50];
    printf("请输入读取的文件名\n");
    scanf("%s",fileName);
	FILE *fp;
    if((fp = fopen(fileName,"rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }

    List *newList = (List*)malloc(sizeof(List));
    List *tem = newList;
    while(fread(tem,sizeof(List),1,fp) == 1)
    {
        List *now = (List*)malloc(sizeof(List));
        tem->next = now;
        now->next = NULL;
        tem = now;
    }
    tem = newList;
    List *target;
    while(tem != NULL)
    {
        if(tem->id == num)
        {
            target = tem;
            break;
        }
        tem = tem->next;
    }
	fclose(fp);
	return target;
}

void InsertList(int x)
{
	List *tem = list;
    for(int i = 0;i<x;i++)
    {
        if(tem == NULL)
        {
            printf("插入位置无效!\n");
            return;
        }
        tem = tem->next;
    }
	List *target = (List*)malloc(sizeof(List));
	target->next = tem->next;
	tem->next = target;
	printf("请输入学号：");
	scanf("%d",&target->id);
	printf("请输入姓名：");
	scanf("%s",target->name);
	printf("请输入班级：");
	scanf("%d",&target->class);
	printf("请输入专业：");
	scanf("%s",target->major);
}

void Delete_major_subject(char major[],int subject,int targetScore)
{
	List *tem = list;
	List *temp = list;
    while(tem != NULL)
    {
        if((strcmp(tem->major,major) == 0) && tem->score[subject] < targetScore)
        {
            while(temp != NULL)
            {
                if(temp->next == tem)
                {
                    break;
                }
                temp = temp->next;
            }
            List *del = temp->next;
            temp->next = tem->next;
            free(del);
        }
        tem = tem->next;
    }
}

void initList()
{
    list = (List*)malloc(sizeof(List));
    list->next = NULL;
    List *tem = list;
    for(int i = 0;i<10;i++)
    {
        List *new = (List*)malloc(sizeof(List));
        new->id = (1000+i);
        //printf("%d\n",new->id);
        strcpy(new->name,"student");
        strcpy(new->major,"软件工程");
        new->class = (i+1);
        for(int j = 0;j<M;j++)
        {
            new->score[j] = (60+i);
        }
        new->next = NULL;
        tem->next = new;
        tem = tem->next;
        //printf("%d\n",new->id);
    }
    list = list->next;
    tem = list;
    //char fileName[50];
    //    printf("请输入存入的文件名\n");
    //    scanf("%s",fileName);
        FILE *fp;
        if((fp = fopen("stuInfo.txt","w")) == NULL)
        {
            printf("OPEN FILE ERROR!\n");
            return;
        }
        while(tem != NULL)
        {
            printf("%d\n",tem->id);
            printf("hahahahahahaha\n");
            fprintf(fp,"%d\t%s\t\t%d\t%-10s\t",tem->id,tem->name,tem->class,tem->major);
            for(int i = 0;i<M;i++)
            {
                fprintf(fp,"%d ",tem->score[i]);
            }
            fprintf(fp,"\n");
            tem = tem->next;
        }
        fclose(fp);
        printf("KKKKKKKKKKKKKKKKK\n");
}

void title()
{
    printf("//////////////////////\n");
}

int main()
{
    initList();
    while(1)
    {
        title();
        int argv;
        scanf("%d",&argv);
        switch(argv)
        {
        case 1:
            {
                CreateList();
                break;
            }
        case 2:
            {
                printf("请输入查询学生的学号\n");
                int id;
                scanf("%d",&id);
                Output(id);
                break;
            }
        case 3:
            {
                Fetch();
                break;
            }
        case 4:
            {
                printf("请输入查询学生的学号\n");
                int num;
                scanf("%d",&num);
                List *tem = Search_num(num);
                show(tem);
                break;
            }
        case 5:
            {
                printf("请输入要插入的位置：");
                int x;
                scanf("%d",&x);
                InsertList(x);
                break;
            }
        case 6:
            {
                printf("请输入【专业】，【课程编号】，【目标成绩】\n");
                printf("【专业】:");
                char major[50];
                scanf("%s",major);
                printf("【课程编号】:");
                int subject;
                scanf("%d",&subject);
                printf("【目标成绩】:");
                int targetScore;
                scanf("%d",&targetScore);
                Delete_major_subject(major,subject,targetScore);
                break;
            }
        case 7:
            {
                allShow();
                break;
            }
        }
    }
}
