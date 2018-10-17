#include<stdio.h>
ADT List
{
    ListLength(L);
    LocateElem(L,e,equal());
    ListInsert(&L,i,e);
}ADT List
void uni(List &La,List Lb)
{
    La_len = ListLength(la);
    Lb_len = ListLength(lb);
    for(int i = 1;i<=Lb_len;i++)
    {
        GetElem(Lb,i,e);
        if(!LocateElem(La,e,equal()))
        {
            ListInsert(La,++La_len,e)
        }
    }
}
int main()
{
    List La,Lb;
    La = {1,3,5,7,9};
    Lb = {2,4,6,8};
    uni(&La,Lb);
    printf("La£º",La);
    return 0;
}
