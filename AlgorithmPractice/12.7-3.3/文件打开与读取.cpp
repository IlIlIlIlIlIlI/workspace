#include<stdio.h>
#include<stdlib.h>
void write()
{
    FILE *fp;
    char ch,filename[10];
    printf("\n������Ҫ�������ļ���:\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("\nCannot open the file!\n");
        exit(0);
    }
    getchar();
    printf("�������ļ����ݣ�\n");
    ch=getchar();
    while(ch!=EOF)
    {
        putc(ch,fp);
        ch=getchar();
    }
    fclose(fp);
}
void read()
{
    FILE *fp;
    char ch,filename[10];
    printf("\n������Ҫ�򿪵��ļ�����\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("\nCannot open the file!\n");
        exit(0);
    }
    getchar();
    printf("�������ļ������ݣ�\n\n");
    ch=getc(fp);
    while(!feof(fp))
    {
        putc(ch,stdout);
        ch=fgetc(fp);
    }
    fclose(fp);
}
int main()
{
    int i;
    void (*select)();
  _1 : printf("\n��ѡ��Ҫ���еĲ�����1-�����ļ���2-���ļ���\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:select=write;  break;
        case 2:select=read;  break;
        default :
            {
                printf("������������,���������룡\n");
                goto _1;
            }
    }
    select();
    return 0;
}
