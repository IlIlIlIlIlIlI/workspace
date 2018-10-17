#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100                                                   //成员数量
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

Student student[N] =                                            //定义结构体数组和初始数据
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

void swap(int *x,int *y)                                        //交换数组中的两个元素
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void scoreAverage(Student stu[])                                //求平均数并且计算总分
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

void toArray_profession(Student stu[],char profession[])        //按专业排序放入数组
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

void toArray_class(Student stu[],int clas)                      //按班级排序放入数组
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

void toArray_leason(Student stu[],int leasonId)                 //按成绩排序放入数组
{
    for(int i = 0;i<N;i++)
    {
        score[i] = stu[i].scores[leasonId];
        id[i] = stu[i].id;
    }
}

void askSave(Student stu[],int n)
//参数Student stu[]：将用户录入的学生信息传入函数，用于保存到文件
//参数int n；将用户期望录入的学生数传入函数，用于保存文件
{
    printf("/************************************\\\n");
    printf("您是否要将录入的学生全部存入文件保存？\n");
    printf("1 ---- 是，2 ---- 否\n");
    printf("\\************************************/\n");
    int a;
    scanf("%d",&a);

    FILE *fp;
    if((fp = fopen("stuInfo.txt","wb")) == NULL)
    {
        printf("WRITE ERROR!");
        return;
    }
    for(int i = 0;i<a;i++)      //通过for循环将用户录入的学生信息存入文件
    {
        if((fwrite(&stu[i],sizeof(Student),1,fp)) != 1)
        {
            printf("信息录入失败，请稍后重试！");
        }
    }
    fclose(fp);
    printf("所有信息已经保存到文件：stuInfo.txt!\n");
}

void Input()                                                    //1.录入学生信息并放入结构体数组
{
    printf("请输入您要录入的学生数：\n");
    int a;
    scanf("%d",&a);     //用于接收用户期望录入的学生数，和后面askSave函数的传参
    Student st[a];      //存入用户录入的学生信息，用于后面askSave函数的传参
    for(int k = 1;k<=a;k++)
    {
        printf("请输入您要录入的第 %d 个学生\n",k);
        Student *stu;       //定义结构体指针，指向student[N]中空的变量的地址
        for(int i = 0;i<N;i++)
        {
            if(student[i].id == 0)
            {
                stu = &student[i];
                st[k-1] = student[i];       //将找到的空的结构体赋值给st[a]数组的元素
                break;                      //找到一个为空的结构体就退出循环
            }
        }
        printf("请输入姓名：");
        scanf("%s",stu->name);
        printf("请输入4位学号：");
        scanf("%d",&(stu->id));
        printf("请输入专业：");
        scanf("%s",stu->profession);
        printf("请输入班级：");
        scanf("%d",&(stu->class));

        for(int i=1 ; i<M+1 ; i++)
        {
            P:
            printf("请输入成绩%d(0~100)：",i);
            scanf("%d",&(stu->scores[i-1]));
            if(((stu->scores[i-1])>=0) && ((stu->scores[i-1])<101))

            {
               continue;
            }
            else
            {
                printf("格式错误请重新输入\n");
                goto P;
            }
        }
    }
    printf("录入成功！\n");
    askSave(st,a);      //调用askSave函数，询问用户是否要将录入的信息存入文件
}

void Output(char nam[])                                         //2.格式化输出
//参数char nam[]：将用户输入的学生姓名传入函数
{
    Student *stu;       //定义结构体指针
    for(int i = 0;i<N;i++)
    {
        if(strcmp(student[i].name,nam) == 0)        //通过for循环找出与目标姓名匹配的学生
        {
            stu = &student[i];      //将匹配到的学生结构体地址存入指针
        }
    }
    printf("学号\t姓名\t专业\t\t班级\t平均分\t\n");
    printf("%d\t%s\t%s\t%d\t%d\n",stu->id,stu->name,stu->profession,stu->class,stu->scoreAverage);
}

void Save(int id)       //3.录入所有学生数据到文件
//参数int id：将用户想要录入的某个学生的id（学号）传入函数
{
    Student *stu;       //定义结构体指针
    for(int i = 0;i<N;i++)
    {
        if(student[i].id == id)     //通过for循环找出与目标学号匹配的学生
        {
            stu = &student[i];
        }
    }
    FILE *fp;
    if((fp = fopen("stuInfo.txt","wb")) == NULL)        //判断要打开的文件是否存在
    {
        printf("WRITE ERROR!");
        return;
    }
    if((fwrite(stu,sizeof(Student),1,fp)) != 1)     //通过二进制的写入形式，将一个STU类型
                                                    //大小的数据块写入文件，便于读写且速度快
    {
        printf("信息录入失败，请稍后重试！");
    }
    fclose(fp);
    printf("成功保存到文件：stuInfo.txt!\n");
}

void Fetch()                                                    //4.随机读取一个学生信息
{
    Student stu;
    FILE *fp;
    if((fp = fopen("stuInfo.txt","rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }
        fseek(fp,random(10)*sizeof(Student),0);     //调用fseek函数，每次读文件的时候强制改
                                                    //变文件指针的标记位置，并且通过定义的宏
                                                    //达到随机改变标记位置的目的
        fread(&stu,sizeof(Student),1,fp);       //以二进制只读的方式读出一个STU类型大小的数据块
        printf("学号\t姓名\t\t专业\t\t\t班级\t成绩1\t成绩2\t成绩3\n");
        printf("%4d\t%-10s\t%-10s\t%4d\t",stu.id,stu.name,stu.profession,stu.class);
        for(int j = 0;j<M;j++)
        {
            printf("%d\t",stu.scores[j]);
        }
        printf("\n");
    rewind(fp);
    fclose(fp);
}

void Max(int leasonId)                                          //5.得出所有学生某门课最高分的学生分数及姓名
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
    printf("%s 获得课程%d的最高分：%d\n",name,leasonId+1,score[N-1]);
}
void Sort_select(Student temp[],char profession[])              //6.
//参数char profession[]：将用户输入的专业传入函数
{

	toArray_profession(temp,profession);
	int scoreLen = N;
    for(int i = 0;i<scoreLen;i++)
    {
        for(int j = i+1;j<scoreLen;j++)
        {
            if(score[i] > score[j])
            {
                swap(&score[i],&score[j]);      //调用swap函数交换两个元素的值
                swap(&id[i],&id[j]);
            }
        }
    }
}

void Sort_buble(Student temp[],int clas)                        //7.
//参数int clas：将用户输入的班级传入函数
{
	toArray_class(temp,clas);       //将与目标班级匹配的学生的平均分存入数组
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
//参数int clas：将用户输入的班级传入函数
{
	toArray_class(temp,clas);       //将与目标班级匹配的学生的平均分存入数组
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
//参数int model：将用户选择的搜索模式传入
//参数int clas：将用户输入的班级传入
//参数int scoe：将用户输入的分数传入
{
    printf("学号\t姓名\t\t专业\t\t\t班级\t总分\t成绩1\t成绩2\t成绩3\t\n");
    //通过逻辑判断符&&，将符合目标的学生筛选出来
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

void all_writeInfo()                                            //录入所有学生数据到文件
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
            printf("信息录入失败，请稍后重试！");
        }
    }

    fclose(fp);
}

void regular_ReadInfo()                                         //99.顺序输出所有数据
{
    Student stu[N];
    FILE *fp;
    if((fp = fopen("stuInfo.txt","rb")) == NULL)
    {
        printf("READ ERROE!");
        return;
    }
    printf("学号\t姓名\t\t专业\t\t\t班级\t成绩1\t成绩2\t成绩3\n");
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
    printf("学号\t姓名\t\t专业\t\t\t班级\t平均分\t\n\n");
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
    printf("\t\t\t\t\t\t|   学生信息管理系统   |\n");
    printf("\t\t\t\t\t\t|                      |\n");
    printf("\t\t\t\t\t\t\\**********************/\n");
    printf("\t\t\t\t+-------------------------------------------------------+\n");
    printf("\t\t\t\t|\t1.录入学生信息                                  |\n");
    printf("\t\t\t\t|\t2.将某个学生信息格式化输出                      |\n");
    printf("\t\t\t\t|\t3.将某个学生信息存入文件                        |\n");
    printf("\t\t\t\t|\t4.从文件随机读取一个学生信息                    |\n");
    printf("\t\t\t\t|\t5.得出所有学生某门课最高分的学生分数及姓名      |\n");
    printf("\t\t\t\t|\t6.对某个专业的学生 按总平均成绩由低到高打印     |\n");
    printf("\t\t\t\t|\t7.对某个班级的学生按总平均成绩由高到低打印      |\n");
    printf("\t\t\t\t|\t8.对某个班级的学生某门课程由低到高排序          |\n");
    printf("\t\t\t\t|\t9.综合查找                                      |\n");
    printf("\t\t\t\t|\t10.顺序输出文件中所有学生数据                   |\n");
    printf("\t\t\t\t|\t11.录入所有学生数据到文件                       |\n");
    printf("\t\t\t\t|\t0.退出系统                                      |\n");
    printf("\t\t\t\t+-------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t*请选择与功能对应的数字*\n");
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
                printf("请输入姓名:\n");
                char a[50];
                scanf("%s",a);
                scoreAverage(student);
                Output(a);
                goto Top;
            }
        case 3:
            {
                printf("请输入学号:\n");
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
                printf("请输入成绩编号:\n");
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
            printf("请输入班级:\n");
            int c;
            scanf("%d",&c);
            Sort_buble(student,c);
            display(score);
            goto Top;
        }
        case 8:
        {

            printf("请输入班级:\n");
            int c;
            scanf("%d",&c);
            scoreAverage(student);
            Sort_insert(student,c);
            display(score);
            goto Top;
        }
         case 9:
            {
                printf("请选择查找模式: 1 ---- 班级+大于下一步所输入的分数    2 ---- 班级+小于下一步所输入的分数\n");
                int x;
                scanf("%d",&x);
                if(x == 1 || x == 2)
                {
                    printf("请输入班级\n");
                    int y;
                    scanf("%d",&y);
                    printf("请输入分数\n");
                    int z;
                    scanf("%d",&z);
                    scoreAverage(student);
                    Search(x,y,z);
                }
                else
                {
                    printf("您的输入有误,请返回重新选择!\n");
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
                printf("全部录入成功!\n");
                goto Top;
            }
        case 0:
            {
                printf("感谢您的使用 再见!\n");
                return 0;
            }
         default:
            {
                printf("\n输入有误请重新选择!\n\n");
                goto Top;
            }
        }
        return 0;
    }
