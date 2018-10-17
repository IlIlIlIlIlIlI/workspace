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

void allOutput(List *p)
{
    List *tem = p;
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

void Output(List *tem)
{
    printf("%d\t%s\t\t%d\t%s\t",tem->id,tem->name,tem->class,tem->major);
    for(int i = 0;i<M;i++)
    {
        printf("%d ",tem->score[i]);
    }
}

void CreateList()
{
	int n;
	printf("��������Ҫ¼���ѧ������\n");
	scanf("%d",&n);
	List *temp = list;
	List *targetTem;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    targetTem = temp;
    List *tem = NULL;
    for(int i = 0;i<n;i++)
        {
            counter++;
            List *new = (List*)malloc(sizeof(list));
            printf("����¼���%d��ѧ������Ϣ��\n",i+1);
            printf("������ѧ�ţ�");
            scanf("%d",&(new->id));
            printf("������������");
            scanf("%s",new->name);
            printf("������༶��");
            scanf("%d",&(new->class));
            printf("������רҵ��");
            scanf("%s",new->major);
            printf("������%d��ɼ�\n",M);
            for(int j = 0;j<M;j++)
            {
                printf("�ɼ�%d:",j+1);
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

void Save(List *p)
{
	printf("�����Ƿ�Ҫ�����ļ���\n");
	printf("1 ---- ��	2 ---- ��\n");
	int ok;
	scanf("%d",&ok);
    if(ok == 1)
    {
        char fileName[50];
        printf("�����������ļ���\n");
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
        printf("����ɹ���\n");
    }
    else if(ok == 2)
    {
        return;
    }
}

void Fetch()
{
    printf("����ǰ������Ϊ��%d��\n",counter);
    char fileName[50];
    printf("�������ȡ���ļ���\n");
    scanf("%s",fileName);
    printf("��ϣ����ȡ�ڼ���ѧ������Ϣ��\n");
    int number;
    scanf("%d",&number);
    if(number > counter)
    {
        printf("����������!\n��ǰ���ȣ�%d\n",counter);
    }
    FILE *fp;
    if((fp = fopen(fileName,"rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }
    List *tem = (List*)malloc(sizeof(List));	//����ָ��
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
    printf("�������ȡ���ļ���\n");
    scanf("%s",fileName);
	FILE *fp;
    if((fp = fopen(fileName,"rb")) == NULL)
    {
        printf("READ ERROE!");
        exit(0);
    }

    List *newList = (List*)malloc(sizeof(List));
    newList->next = NULL;
    List *tem = newList;
    List *target;
    while(fread(tem,sizeof(List),1,fp) == 1)
    {
        if(tem->id == num)
        {
            target = tem;
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
    for(int i = 0;i<x-1;i++)
    {
        if(tem == NULL)
        {
            printf("����λ����Ч!\n");
            return;
        }
        tem = tem->next;
    }
    target->next = tem->next;
    tem->next = target;
	printf("������ѧ�ţ�");
	scanf("%d",&(target->id));
	printf("������������");
	scanf("%s",target->name);
	printf("������༶��");
	scanf("%d",&(target->class));
	printf("������רҵ��");
	scanf("%s",target->major);
	for(int j = 0;j<M;j++)
    {
        printf("�ɼ�%d:",j+1);
        scanf("%d",&(target->score[j]));
    }
	printf("��Ϣ������ɣ��Ƿ�չʾ��\n");
	printf("1 ---- ��    2 ---- ��\n");
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
    printf(" ɾ���ɹ���\n");
}

List* Search_major_subject(char major[],int subject,int targetScore)
{
    List *tem = list;
	List *newList = (List*)malloc(sizeof(list));
	List *temp = newList;
    while(tem != NULL)
    {
        if((strcmp(tem->major,major) == 0) && tem->score[subject] < targetScore)
        {
            List *new = tem;
            temp->next = new;
            temp = temp->next;
        }
        tem = tem->next;
    }
    temp->next = NULL;
    newList = newList->next;
    printf("������ϣ��Ƿ����չʾ��\n");
    printf("1 ---- ��    2 ---- ��\n");
    int ok;
	scanf("%d",&ok);
    if(ok == 1)
    {
        allOutput(newList);
    }
    else if(ok == 2)
    {
        return;
    }
    return newList;
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
        strcpy(new->major,"�������");
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
        if((fp = fopen("stuInfo.txt","w")) == NULL)
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
        printf("��ʼ��ѧ����Ϣ��ɣ�\n");
        printf("Ĭ�ϴ��浽�ļ���stuInfo.txt!\n");
}

void title()
{
    printf("\n\t\t\t\t\t/**********************\\\n");
    printf("\t\t\t\t\t|                      |\n");
    printf("\t\t\t\t\t|   ѧ����Ϣ����ϵͳ   |\n");
    printf("\t\t\t\t\t|                      |\n");
    printf("\t\t\t\t\t\\**********************/\n");
    printf("\t\t\t+-------------------------------------------------------+\n");
    printf("\t\t\t|\t1.����ѧ����Ϣ����                              |\n");
    printf("\t\t\t|\t2.���ļ������ȡһ��ѧ����Ϣ                    |\n");
    printf("\t\t\t|\t3.����ָ��ѧ�ŵ�ѧ��                            |\n");
    printf("\t\t\t|\t4.����ѧ����Ϣ����������                        |\n");
    printf("\t\t\t|\t5.ɾ��ָ��ѧ�ŵ�ѧ����Ϣ                        |\n");
    printf("\t\t\t|\t6.�ۺϲ���                                      |\n");
    printf("\t\t\t|\t7.�ۺ�ɾ��                                      |\n");
    printf("\t\t\t|\t8.˳���������ѧ������                          |\n");
    printf("\t\t\t|\t9.�˳�ϵͳ                                      |\n");
    printf("\t\t\t+-------------------------------------------------------+\n");
    printf("������������ѡ����:\n");
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
                Fetch();
                break;
            }
        case 3:
            {
                printf("�������ѯѧ����ѧ��\n");
                int num;
                scanf("%d",&num);
                List *tem = Search_num(num);
                Output(tem);
                break;
            }
        case 4:
            {
                printf("��ǰ������Ϊ��%d\n",counter);
                printf("������Ҫ�����λ�ã�");
                int x;
                scanf("%d",&x);
                InsertList(x);
                break;
            }
        case 5:
            {
                printf("������ɾ��ѧ����Ϣ��ѧ��\n");
                int num;
                scanf("%d",&num);
                Delete_num(num);
                break;
            }
        case 6:
            {
                printf("�����롾רҵ�������γ̱�š�����Ŀ��ɼ���\n");
                printf("��רҵ��:");
                char major[50];
                scanf("%s",major);
                printf("���γ̱�š�:");
                int subject;
                scanf("%d",&subject);
                printf("��Ŀ��ɼ���:");
                int targetScore;
                scanf("%d",&targetScore);
                Search_major_subject(major,subject,targetScore);
                break;
            }
        case 7:
            {
                printf("�����롾רҵ�������γ̱�š�����Ŀ��ɼ���\n");
                printf("��רҵ��:");
                char major[50];
                scanf("%s",major);
                printf("���γ̱�š�:");
                int subject;
                scanf("%d",&subject);
                printf("��Ŀ��ɼ���:");
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
                printf("�˳��ɹ���\n");
                return 0;
            }
        default:
            {
                printf("\n��������������ѡ��!\n\n");
                break;
            }
        }
    }
}



