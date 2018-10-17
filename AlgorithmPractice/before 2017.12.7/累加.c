#include<stdio.h>
#include<math.h>
void main(){
int i=1,sum=0;
while(i<=10000000)
{
    sum+=i;
    i++;
}
printf("Sum=%d",sum);
}
