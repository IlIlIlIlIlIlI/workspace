#include<stdio.h>
#include<stdlib.h>
void write()
{
    FILE *fp;
    char ch,filename[10];
    printf("\n请输入要创建的文件名:\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("\nCannot open the file!\n");
        exit(0);
    }
    getchar();
    printf("请输入文件内容：\n");
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
    printf("\n请输入要打开的文件名：\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("\nCannot open the file!\n");
        exit(0);
    }
    getchar();
    printf("以下是文件的内容：\n\n");
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
  _1 : printf("\n请选择要进行的操作：1-创建文件；2-打开文件。\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:select=write;  break;
        case 2:select=read;  break;
        default :
            {
                printf("您的输入有误,请重新输入！\n");
                goto _1;
            }
    }
    select();
    return 0;
}
