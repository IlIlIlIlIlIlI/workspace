#include<stdio.h>
int FindMax(int *p,int n)
{
    int i,ma;
    ma= *p++;
    for(i=0;i<n;i++)
    {
        if(ma<*p) ma=*p;
        p++;
    }
    return ma;
}
int FindMin(int *p,int n)
{
    int i,mi;
    mi= *p++;
    for(i=0;i<n;i++)
    {
        if(mi>*p) mi=*p;
        p++;
    }
    return mi;
}
int Find(int *p,int n)
{
    int tem;
    int (*fin)(int *p,int n);
    puts("��ѡ��1-�������ֵ��2-������Сֵ��");
    scanf("%d",&tem);
    getchar();
    switch(tem)
    {
    case 1:
        fin=FindMax;  break;
    case 2:
        fin=FindMin;  break;
    }
    tem=fin(p,n);
    return tem;
}
int mian()
{
    int a[100000];
    int i,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    getchar();
    printf("Ҫ���ҵ�ֵΪ��%d\n",Find(a,n));
    return 0;
}
