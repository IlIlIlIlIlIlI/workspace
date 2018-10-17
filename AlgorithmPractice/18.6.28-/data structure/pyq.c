#include<stdio.h>
#include<stdlib.h>
#define M 3

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
int counter;

void CreateList()
{
	int n;
	printf("请输入您要录入的学生数：\n");
	scanf("%d",&n);
	List *tem = list;
	List *targetTem;
    while(tem != NULL)
    {
        if(tem->next == NULL)
        {
            targetTem = tem;
            break;
        }
        tem = tem->next;
    }
    tem = tem->next;
    targetTem->next = NULL;
    for(int i = 0;i<n;i++)
        {
            counter++;
            List *new = (List*)malloc(sizeof(List));
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
                printf("课程%d：",j+1);
                scanf("%d",&(new->score[j]));
            }
            if(tem == NULL)
            {
                counter++;
                new->next = NULL;
                tem = new;
                continue;
            }
            new->next = tem;
            tem = new;
        }
        targetTem->next = tem;
	Save(list);
}

void allOutput(List *p)
{
    printf("学号\t姓名\t\t班级\t专业\t\t");
    for(int i = 1;i<=M;i++)
    {
        printf("成绩%d\t",i);
    }
    printf("\n");
    List *tem = p;
    while(tem != NULL)
    {
        printf("%d\t%s\t\t%d\t%-10s\t",tem->id,tem->name,tem->class,tem->major);
        for(int i = 0;i<M;i++)
        {
            printf("%d\t",tem->score[i]);
        }
        tem = tem->next;
        printf("\n");
    }
}

void Output(List *tem)
{
    printf("学号\t姓名\t\t班级\t专业\t\t");
    for(int i = 1;i<=M;i++)
    {
        printf("成绩%d\t",i);
    }
    printf("\n");
    printf("%d\t%s\t\t%d\t%s\t",tem->id,tem->name,tem->class,tem->major);
    for(int i = 0;i<M;i++)
    {
        printf("%d\t",tem->score[i]);
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
            if((fwrite(tem,sizeof(List),1,fp)) != 1)
            {
                printf("WRITE ERROR!\n");
            }
            tem = tem->next;
        }
        fclose(fp);
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
    printf("您希望读取第几个学生的信息？\n");
    int number;
    scanf("%d",&number);
    if(number > counter)
    {
        printf("超出链表长度!\n当前长度：%d\n",counter);
    }
    FILE *fp;
    if((fp = fopen(fileName,"rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }
    List *tem = (List*)malloc(sizeof(List));	//存入指针
    fseek(fp,number*sizeof(List),0);
    fread(tem,sizeof(List),1,fp);
	printf("%d\t%s\t\t%d\t%-10s\t",tem->id,tem->name,tem->class,tem->major);
	for(int i = 0;i<M;i++)
    {
        printf("%d ",tem->score[i]);
    }
    printf("\n");
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
        exit(0);
    }
    List *target = (List*)malloc(sizeof(List));
    while(fread(target,sizeof(List),1,fp) == 1)
    {
        if(target->id == num)
        {
            break;
        }
    }
	fclose(fp);
	return target;
}

void InsertList(int x)
{
    List *tem = list;
	List *target = (List*)malloc(sizeof(List));
    for(int i = 1;i<x;i++)
    {
        if(tem == NULL)
        {
            printf("插入位置无效!\n");
            return;
        }
        tem = tem->next;
    }
    target->next = tem->next;
    tem->next = target;
	printf("请输入学号：");
	scanf("%d",&(target->id));
	printf("请输入姓名：");
	scanf("%s",target->name);
	printf("请输入班级：");
	scanf("%d",&(target->class));
	printf("请输入专业：");
	scanf("%s",target->major);
	for(int j = 0;j<M;j++)
    {
        printf("课程%d：",j+1);
        scanf("%d",&(target->score[j]));
    }
	printf("插入完成，是否展示？\n");
	printf("1 ---- 是    2 ---- 否\n");
	int ok;
	scanf("%d",&ok);
    if(ok == 1)
    {
        allOutput(list);
    }
    else if(ok == 2)
    {
        return;
    }
}

void Delete_num(int num)
{
    List *tem = list;
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
	List *temp = list;
	if(target == list)
    {
        list = list->next;
        free(target);
    }
    else
    {
        while(temp->next != target)
        {
            temp = temp->next;
        }
        List *del = temp->next;
        temp->next = target->next;
        free(del);
    }
    printf(" 删除成功！\n");
}

void Search_major_subject(char major[],int subject,int targetScore)
{
    List *tem = list;
    List *newList = (List*)malloc(sizeof(List));
    newList->next = NULL;
    newList = newList->next;
    List *newTem = newList;
    while(tem != NULL)
    {
        if((strcmp(tem->major,major) == 0) && tem->score[subject] < targetScore)
        {
            List *new = (List*)malloc(sizeof(List));
            new = tem;
            new->next = NULL;
            newTem->next = new;
            newTem = newTem->next;
            //Output(tem);
        }
        tem = tem->next;
    }
    newList = newList->next;
    Output(newList);
}


void Delete_major_subject(char major[],int subject,int targetScore)
{
	List *tem = list;
	List *temp = list;
    while(tem != NULL)
    {
        if((strcmp(tem->major,major) == 0) && tem->score[subject] < targetScore)
        {
            if(tem == list)
            {
                list = list->next;
                List *del = tem;
                free(del);
            }
            else
            {
                while(temp->next != tem)
                {
                    temp = temp->next;
                }
                List *del = temp->next;
                temp->next = tem->next;
                free(del);
            }
        }
        tem = tem->next;
    }
    printf("删除完毕，是否输出展示？\n");
    printf("1 ---- 是    2 ---- 否\n");
    int ok;
	scanf("%d",&ok);
    if(ok == 1)
    {
        allOutput(list);
    }
    else if(ok == 2)
    {
        return;
    }
}

void initList()
{
    counter = 0;
    list = (List*)malloc(sizeof(List));
    list->next = NULL;
    List *tem = list;
    for(int i = 0;i<10;i++)
    {
        counter++;
        List *new = (List*)malloc(sizeof(List));
        new->id = (1000+i);
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
    }
    list = list->next;
    tem = list;
        FILE *fp;
        if((fp = fopen("stuInfo.txt","wb")) == NULL)
        {
            printf("OPEN FILE ERROR!\n");
            return;
        }
        while(tem != NULL)
        {
            if((fwrite(tem,sizeof(List),1,fp)) != 1)
            {
                printf("WRITE ERROR!\n");
            }
            tem = tem->next;
        }
        fclose(fp);
        printf("初始化学生信息完成！\n");
        printf("默认储存到文件：stuInfo.txt!\n");
}

void title()
{
    printf("\t+-------------------------------------------------------+\n");
    printf("\t|\t1.创建学生信息链表                              |\n");
    printf("\t|\t2.从文件随机读取一个学生信息                    |\n");
    printf("\t|\t3.查找指定学号的学生                            |\n");
    printf("\t|\t4.输入学生信息并插入链表                        |\n");
    printf("\t|\t5.删除指定学号的学生信息                        |\n");
    printf("\t|\t6.综合查找                                      |\n");
    printf("\t|\t7.综合删除                                      |\n");
    printf("\t|\t8.顺序输出所有学生数据                          |\n");
    printf("\t|\t9.退出系统                                      |\n");
    printf("\t+-------------------------------------------------------+\n");
    printf("\n");
    printf("请选择输入数字以选择功能：");
}

int main()
{
    initList();
    while(1)
    {
        title();
        int argv;
        scanf("%d",&argv);
        printf("\n");
        switch(argv)
        {
        case 1:
            {
                CreateList();
                break;
            }
        case 2:
            {
                printf("\n当前链表长度为：%d\n",counter);
                Fetch();
                break;
            }
        case 3:
            {
                printf("\n请输入查询学生的学号\n");
                int num;
                scanf("%d",&num);
                List *tem = Search_num(num);
                Output(tem);
                break;
            }
        case 4:
            {
                printf("\n当前链表长度为：%d\n",counter);
                printf("请输入要插入的位置：");
                int x;
                scanf("%d",&x);
                InsertList(x);
                break;
            }
        case 5:
            {
                printf("\n请输入删除学生信息的学号\n");
                int num;
                scanf("%d",&num);
                Delete_num(num);
                break;
            }
        case 6:
            {
                printf("\n请输入【专业】，【课程编号】，【目标成绩】\n");
                printf("【专业】:");
                char major[50];
                scanf("%s",major);
                printf("【课程编号】:");
                int subject;
                scanf("%d",&subject);
                printf("【目标成绩】:");
                int targetScore;
                scanf("%d",&targetScore);
                Search_major_subject(major,subject,targetScore);
                break;
            }
        case 7:
            {
                printf("\n请输入【专业】，【课程编号】，【目标成绩】\n");
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
        case 8:
            {
                allOutput(list);
                break;
            }
        case 9:
            {
                printf("\n退出成功！\n");
                break;
            }
        default:
            {
                printf("\n输入有误请重新选择!\n\n");
                break;
            }
        }
    }
}
