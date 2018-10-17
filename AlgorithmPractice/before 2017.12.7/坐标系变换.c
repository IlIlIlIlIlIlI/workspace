#include<stdio.h>
int x,y,z,k,i,j,p;
int get_id(int k,int i,int j,int p)
{
    if(k=0){x=j;y=i;z=p;}
    if(k=1){x=p;y=i;z=j;}
    if(k=2){x=j;y=i;z=p;}
    if(k=3){x=p;y=i;z=j;}
    if(k=4){x=j;y=p;z=i;}
    if(k=5){x=j;y=p;z=i;}
}
int main()
{
    scanf("%d%d%d%d",&k,&i,&j,&p);
    get_id(k,i,j,p);
    printf("%d %d %d\n",x,y,z);
    return 0;
}

