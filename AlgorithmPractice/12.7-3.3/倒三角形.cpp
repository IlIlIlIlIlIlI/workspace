#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        //��Ϊ�������ε�����ͼ�������ҶԳƵ�
        //��������������Ŀո����󣬾Ͳ��ù��ұߵĿո������
        //ֱ�������\n��
        for(int j=1;j<=2*n-i;j++)
            {
                if(j<i)  printf(" ");
                else     printf("*");
            }
            printf("\n");
    }
    return 0;
}
