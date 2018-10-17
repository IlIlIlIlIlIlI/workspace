#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100                                                   //��Ա����
#define M 3
#define random(x) (rand()%(x+1))

char professions[][50] = {"Computer Science","Software Engineering"};
int score[N];
int id[N];

typedef struct Student
{
	int id;
	char name[50];
	char profession[50];
	int class;
	int scores[M];
	int scoreAverage;
	int scoreSum;
}Student;

Student student[N] =                                            //����ṹ������ͳ�ʼ����
            {
                {3742,"Person1","Software Engineering",4,54,86,89,0},
				{2333,"Person2","Software Engineering",4,34,56,34,0},
				{2233,"Person3","Software Engineering",4,54,66,56,0},
				{8484,"Person4","Software Engineering",4,54,55,89,0},
				{9473,"Person5","Software Engineering",4,54,77,45,0},
				{7846,"Person6","Software Engineering",4,54,86,78,0},
				{1343,"Person7","Software Engineering",4,54,23,89,0},
				{9643,"Person8","Software Engineering",4,23,86,89,0},
				{1235,"Person9","Software Engineering",4,89,86,85,0},
				{9537,"Person0","Software Engineering",4,99,87,86,0}
            };

void swap(int *x,int *y)                                        //���������е�����Ԫ��
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void scoreAverage(Student stu[])                                //��ƽ�������Ҽ����ܷ�
{
	for(int i = 0;i<N;i++)
{
    int sum = 0;
    for(int j = 0;j<M;j++)
    {
        sum += stu[i].scores[j];
    }
	stu[i].scoreAverage = sum/3;
	stu[i].scoreSum = sum;
}
}

void toArray_profession(Student stu[],char profession[])        //��רҵ�����������
{
    for(int i = 0;i<N;i++)
    {
        if((strcmp(stu[i].profession,profession) == 0) && stu[i].id != 0)
        {
            score[i] = stu[i].scoreAverage;
            id[i] = stu[i].id;
        }
    }
}

void toArray_class(Student stu[],int clas)                      //���༶�����������
{
	for(int i = 0;i<N;i++)
{
	if(stu[i].class == clas && stu[i].id != 0)
{
	score[i] = stu[i].scoreAverage;
	id[i] = stu[i].id;
}
}
}

void toArray_leason(Student stu[],int leasonId)                 //���ɼ������������
{
    for(int i = 0;i<N;i++)
    {
        score[i] = stu[i].scores[leasonId];
        id[i] = stu[i].id;
    }
}

void askSave(Student stu[],int n)
//����Student stu[]�����û�¼���ѧ����Ϣ���뺯�������ڱ��浽�ļ�
//����int n�����û�����¼���ѧ�������뺯�������ڱ����ļ�
{
    printf("/************************************\\\n");
    printf("���Ƿ�Ҫ��¼���ѧ��ȫ�������ļ����棿\n");
    printf("1 ---- �ǣ�2 ---- ��\n");
    printf("\\************************************/\n");
    int a;
    scanf("%d",&a);

    FILE *fp;
    if((fp = fopen("stuInfo.txt","wb")) == NULL)
    {
        printf("WRITE ERROR!");
        return;
    }
    for(int i = 0;i<a;i++)      //ͨ��forѭ�����û�¼���ѧ����Ϣ�����ļ�
    {
        if((fwrite(&stu[i],sizeof(Student),1,fp)) != 1)
        {
            printf("��Ϣ¼��ʧ�ܣ����Ժ����ԣ�");
        }
    }
    fclose(fp);
    printf("������Ϣ�Ѿ����浽�ļ���stuInfo.txt!\n");
}

void Input()                                                    //1.¼��ѧ����Ϣ������ṹ������
{
    printf("��������Ҫ¼���ѧ������\n");
    int a;
    scanf("%d",&a);     //���ڽ����û�����¼���ѧ�������ͺ���askSave�����Ĵ���
    Student st[a];      //�����û�¼���ѧ����Ϣ�����ں���askSave�����Ĵ���
    for(int k = 1;k<=a;k++)
    {
        printf("��������Ҫ¼��ĵ� %d ��ѧ��\n",k);
        Student *stu;       //����ṹ��ָ�룬ָ��student[N]�пյı����ĵ�ַ
        for(int i = 0;i<N;i++)
        {
            if(student[i].id == 0)
            {
                stu = &student[i];
                st[k-1] = student[i];       //���ҵ��ĿյĽṹ�帳ֵ��st[a]�����Ԫ��
                break;                      //�ҵ�һ��Ϊ�յĽṹ����˳�ѭ��
            }
        }
        printf("������������");
        scanf("%s",stu->name);
        printf("������4λѧ�ţ�");
        scanf("%d",&(stu->id));
        printf("������רҵ��");
        scanf("%s",stu->profession);
        printf("������༶��");
        scanf("%d",&(stu->class));

        for(int i=1 ; i<M+1 ; i++)
        {
            P:
            printf("������ɼ�%d(0~100)��",i);
            scanf("%d",&(stu->scores[i-1]));
            if(((stu->scores[i-1])>=0) && ((stu->scores[i-1])<101))

            {
               continue;
            }
            else
            {
                printf("��ʽ��������������\n");
                goto P;
            }
        }
    }
    printf("¼��ɹ���\n");
    askSave(st,a);      //����askSave������ѯ���û��Ƿ�Ҫ��¼�����Ϣ�����ļ�
}

void Output(char nam[])                                         //2.��ʽ�����
//����char nam[]�����û������ѧ���������뺯��
{
    Student *stu;       //����ṹ��ָ��
    for(int i = 0;i<N;i++)
    {
        if(strcmp(student[i].name,nam) == 0)        //ͨ��forѭ���ҳ���Ŀ������ƥ���ѧ��
        {
            stu = &student[i];      //��ƥ�䵽��ѧ���ṹ���ַ����ָ��
        }
    }
    printf("ѧ��\t����\tרҵ\t\t�༶\tƽ����\t\n");
    printf("%d\t%s\t%s\t%d\t%d\n",stu->id,stu->name,stu->profession,stu->class,stu->scoreAverage);
}

void Save(int id)       //3.¼������ѧ�����ݵ��ļ�
//����int id�����û���Ҫ¼���ĳ��ѧ����id��ѧ�ţ����뺯��
{
    Student *stu;       //����ṹ��ָ��
    for(int i = 0;i<N;i++)
    {
        if(student[i].id == id)     //ͨ��forѭ���ҳ���Ŀ��ѧ��ƥ���ѧ��
        {
            stu = &student[i];
        }
    }
    FILE *fp;
    if((fp = fopen("stuInfo.txt","wb")) == NULL)        //�ж�Ҫ�򿪵��ļ��Ƿ����
    {
        printf("WRITE ERROR!");
        return;
    }
    if((fwrite(stu,sizeof(Student),1,fp)) != 1)     //ͨ�������Ƶ�д����ʽ����һ��STU����
                                                    //��С�����ݿ�д���ļ������ڶ�д���ٶȿ�
    {
        printf("��Ϣ¼��ʧ�ܣ����Ժ����ԣ�");
    }
    fclose(fp);
    printf("�ɹ����浽�ļ���stuInfo.txt!\n");
}

void Fetch()                                                    //4.�����ȡһ��ѧ����Ϣ
{
    Student stu;
    FILE *fp;
    if((fp = fopen("stuInfo.txt","rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }
        fseek(fp,random(10)*sizeof(Student),0);     //����fseek������ÿ�ζ��ļ���ʱ��ǿ�Ƹ�
                                                    //���ļ�ָ��ı��λ�ã�����ͨ������ĺ�
                                                    //�ﵽ����ı���λ�õ�Ŀ��
        fread(&stu,sizeof(Student),1,fp);       //�Զ�����ֻ���ķ�ʽ����һ��STU���ʹ�С�����ݿ�
        printf("ѧ��\t����\t\tרҵ\t\t\t�༶\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
        printf("%4d\t%-10s\t%-10s\t%4d\t",stu.id,stu.name,stu.profession,stu.class);
        for(int j = 0;j<M;j++)
        {
            printf("%d\t",stu.scores[j]);
        }
        printf("\n");
    rewind(fp);
    fclose(fp);
}

void Max(int leasonId)                                          //5.�ó�����ѧ��ĳ�ſ���߷ֵ�ѧ������������
{
    toArray_leason(student,leasonId);
    int scoreLen = N;
	for(int i = 0;i<scoreLen;i++)
{
	for(int j = i+1;j<scoreLen;j++)
{
	if(score[i] > score[j])
{
	swap(&score[i],&score[j]);
	swap(&id[i],&id[j]);
}
}
}
char *name;
for(int i = 0;i<N;i++)
{
    if(student[i].id == id[N-1])
        {
            name = student[i].name;
        }
}
    printf("%s ��ÿγ�%d����߷֣�%d\n",name,leasonId+1,score[N-1]);
}
void Sort_select(Student temp[],char profession[])              //6.
//����char profession[]�����û������רҵ���뺯��
{

	toArray_profession(temp,profession);
	int scoreLen = N;
    for(int i = 0;i<scoreLen;i++)
    {
        for(int j = i+1;j<scoreLen;j++)
        {
            if(score[i] > score[j])
            {
                swap(&score[i],&score[j]);      //����swap������������Ԫ�ص�ֵ
                swap(&id[i],&id[j]);
            }
        }
    }
}

void Sort_buble(Student temp[],int clas)                        //7.
//����int clas�����û�����İ༶���뺯��
{
	toArray_class(temp,clas);       //����Ŀ��༶ƥ���ѧ����ƽ���ִ�������
	int scoreLen = N;
	for(int i = 0;i<scoreLen-1;i++)
    {
        for(int j = 0;j<scoreLen-1-i;j++)
        {
            if(score[j]<score[j+1])
            {
                swap(&score[j],&score[j+1]);
                swap(&id[j],&id[j+1]);
            }
        }
    }
}

void Sort_insert(Student temp[],int clas)                       //8.
//����int clas�����û�����İ༶���뺯��
{
	toArray_class(temp,clas);       //����Ŀ��༶ƥ���ѧ����ƽ���ִ�������
	for(int i = 1;i<N;i++)
    {
        int j;
        int insert = score[i];
        int insert_id = id[i];
        for(j = i-1;j>=0 && score[j] > insert;j--)
        {
            score[j+1] = score[j];
            id[j+1] = id[j];
        }
        score[j+1] = insert;
        id[j+1] = insert_id;
    }

}

void Search(int model,int clas,int scoe)
//����int model�����û�ѡ�������ģʽ����
//����int clas�����û�����İ༶����
//����int scoe�����û�����ķ�������
{
    printf("ѧ��\t����\t\tרҵ\t\t\t�༶\t�ܷ�\t�ɼ�1\t�ɼ�2\t�ɼ�3\t\n");
    //ͨ���߼��жϷ�&&��������Ŀ���ѧ��ɸѡ����
    if(model == 1)
    {
        for(int i = 0;i<N;i++)
        {
            if(student[i].scoreSum > scoe && student[i].class == clas)
            {
                printf("%4d\t%-10s\t%-10s\t%4d\t%4d\t",student[i].id,student[i].name,student[i].profession,student[i].class,student[i].scoreSum);
                for(int j = 0;j<M;j++)
                {
                    printf("%d\t",student[i].scores[j]);
                }
                printf("\n");
            }
        }
    }
    if(model == 2)
    {
        for(int i = 0;i<N;i++)
        {
            if(student[i].scoreSum < scoe && student[i].class == clas)
            {
                printf("%4d\t%-10s\t%-10s\t%4d\t%4d\t",student[i].id,student[i].name,student[i].profession,student[i].class,student[i].scoreSum);
                for(int j = 0;j<M;j++)
                {
                    printf("%d\t",student[i].scores[j]);
                }
                printf("\n");
            }
        }
    }
}

void all_writeInfo()                                            //¼������ѧ�����ݵ��ļ�
{
    Student *stu = student;

    //printf("%d",stu->class);

    FILE *fp;
    if((fp = fopen("stuInfo.txt","wb")) == NULL)
    {
        printf("WRITE ERROR!");
        return;
    }
    for(int i = 0;i<N;i++)
    {
        if((fwrite(stu+i,sizeof(Student),1,fp)) != 1)
        {
            printf("��Ϣ¼��ʧ�ܣ����Ժ����ԣ�");
        }
    }

    fclose(fp);
}

void regular_ReadInfo()                                         //99.˳�������������
{
    Student stu[N];
    FILE *fp;
    if((fp = fopen("stuInfo.txt","rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }
    printf("ѧ��\t����\t\tרҵ\t\t\t�༶\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
    for(int i = 0;i<N;i++)
    {
        fread(&stu[i],sizeof(Student),1,fp);
        //printf("%d",(int)stu.id);

        if(stu[i].id != 0)
        {
            printf("%4d\t%-10s\t%-10s\t%4d\t",stu[i].id,stu[i].name,stu[i].profession,stu[i].class);
            for(int j = 0;j<M;j++)
            {
                printf("%d\t",stu[i].scores[j]);
            }
            printf("\n");
        }
    }
    fclose(fp);
}

void display(int score[])
{
    printf("ѧ��\t����\t\tרҵ\t\t\t�༶\tƽ����\t\n\n");
	for(int i = 0;i<N;i++)
{
    for(int j = 0;j<N;j++)
    {
        if(student[j].id == id[i] && student[j].id !=0)
        {
            printf("%4d \t %s \t %s \t %2d \t %3d \n",student[j].id,student[j].name,student[j].profession,student[j].class,score[i]);
        }
    }

}
	printf("\n");
}

void initTitle()
{
    memset(score,0,sizeof(int)*N);
    memset(id,0,sizeof(int)*N);
    printf("\t\t\t\t\t\t/**********************\\\n");
    printf("\t\t\t\t\t\t|                      |\n");
    printf("\t\t\t\t\t\t|   ѧ����Ϣ����ϵͳ   |\n");
    printf("\t\t\t\t\t\t|                      |\n");
    printf("\t\t\t\t\t\t\\**********************/\n");
    printf("\t\t\t\t+-------------------------------------------------------+\n");
    printf("\t\t\t\t|\t1.¼��ѧ����Ϣ                                  |\n");
    printf("\t\t\t\t|\t2.��ĳ��ѧ����Ϣ��ʽ�����                      |\n");
    printf("\t\t\t\t|\t3.��ĳ��ѧ����Ϣ�����ļ�                        |\n");
    printf("\t\t\t\t|\t4.���ļ������ȡһ��ѧ����Ϣ                    |\n");
    printf("\t\t\t\t|\t5.�ó�����ѧ��ĳ�ſ���߷ֵ�ѧ������������      |\n");
    printf("\t\t\t\t|\t6.��ĳ��רҵ��ѧ�� ����ƽ���ɼ��ɵ͵��ߴ�ӡ     |\n");
    printf("\t\t\t\t|\t7.��ĳ���༶��ѧ������ƽ���ɼ��ɸߵ��ʹ�ӡ      |\n");
    printf("\t\t\t\t|\t8.��ĳ���༶��ѧ��ĳ�ſγ��ɵ͵�������          |\n");
    printf("\t\t\t\t|\t9.�ۺϲ���                                      |\n");
    printf("\t\t\t\t|\t10.˳������ļ�������ѧ������                   |\n");
    printf("\t\t\t\t|\t11.¼������ѧ�����ݵ��ļ�                       |\n");
    printf("\t\t\t\t|\t0.�˳�ϵͳ                                      |\n");
    printf("\t\t\t\t+-------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t*��ѡ���빦�ܶ�Ӧ������*\n");
    printf("\n");
}

int main()
{
    Top:

    initTitle();

    int i;
    scanf("%d",&i);
    switch(i)
    {

        case 1:
            {
                Input();
                goto Top;
            }
        case 2:
            {
                printf("����������:\n");
                char a[50];
                scanf("%s",a);
                scoreAverage(student);
                Output(a);
                goto Top;
            }
        case 3:
            {
                printf("������ѧ��:\n");
                int p;
                scanf("%d",&p);
                Save(p);
                goto Top;
            }
        case 4:
            {
                Fetch();
                goto Top;
            }
        case 5:
            {
                printf("������ɼ����:\n");
                int p;
                scanf("%d",&p);
                Max(p-1);
                goto Top;
            }
        case 6:
        {
            //char pro[50];
            //printf("");
            //scanf("%s",pro);
            scoreAverage(student);
            Sort_select(student,"Software Engineering");
            display(score);
            goto Top;
        }
        case 7:
        {
            scoreAverage(student);
            printf("������༶:\n");
            int c;
            scanf("%d",&c);
            Sort_buble(student,c);
            display(score);
            goto Top;
        }
        case 8:
        {

            printf("������༶:\n");
            int c;
            scanf("%d",&c);
            scoreAverage(student);
            Sort_insert(student,c);
            display(score);
            goto Top;
        }
         case 9:
            {
                printf("��ѡ�����ģʽ: 1 ---- �༶+������һ��������ķ���    2 ---- �༶+С����һ��������ķ���\n");
                int x;
                scanf("%d",&x);
                if(x == 1 || x == 2)
                {
                    printf("������༶\n");
                    int y;
                    scanf("%d",&y);
                    printf("���������\n");
                    int z;
                    scanf("%d",&z);
                    scoreAverage(student);
                    Search(x,y,z);
                }
                else
                {
                    printf("������������,�뷵������ѡ��!\n");
                }
                goto Top;
            }
        case 10:
            {
                regular_ReadInfo();
                goto Top;
            }
        case 11:
            {
                all_writeInfo();
                printf("ȫ��¼��ɹ�!\n");
                goto Top;
            }
        case 0:
            {
                printf("��л����ʹ�� �ټ�!\n");
                return 0;
            }
         default:
            {
                printf("\n��������������ѡ��!\n\n");
                goto Top;
            }
        }
        return 0;
    }
