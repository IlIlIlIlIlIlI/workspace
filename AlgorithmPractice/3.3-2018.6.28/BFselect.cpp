//BFƥ���㷨
#include<stdio.h>
#include<string.h>
int sel(char* n,char* m)
{
    int i = 0;
    int j = 0;
    while(i<strlen(n) && j<strlen(m))
    {
        if(n[i] == m[j])
        {
            i++;
            j++;
        }
        else
        {
            //ƥ��ʧ�ܣ���¼ƥ����ȵ�ָ��i����i-j+1�Ļ��˶�����ָ����ݣ�
            i = i-j+1;
            j = 0;
        }
    }
        //����ѭ�������ֿ���
        //1.������������
        //2.ģʽ��������ɣ�ƥ��ɹ�
        if(j == strlen(m))
            return i-strlen(m)+1;
        return 0;  //***����***

}
int main()
{
    char a[]={"abcdefhhde"};
    char b[]={"de"};
    int add = sel(a,b);
    printf("%d",add);
}
/*
ʱ�临�Ӷȣ�
1.O(m),mΪģʽ���ĳ��ȣ�����һ��ƥ��ͳɹ�
2.������O(n+m)
3.������O(n*m),��00000001��001��ƥ�䵽���������һ����֪��ƥ��ɹ���������n*m��
*/
