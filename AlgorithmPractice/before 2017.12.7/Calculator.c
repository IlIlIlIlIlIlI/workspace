#include<stdio.h>
#include<math.h>
int main(){void act1(float,float),act2(float,float),act3(float,float),act4(float,float);
printf("Please assign values to x and y to calculate!\n\n");
 float x,y;
 char ch;
 scanf("%f",&x);
 ch=getchar();
 scanf("%f",&y);
 switch(ch)
 {
 case'+':act1(x,y);break;
 case'-':act2(x,y);break;
 case'*':act3(x,y);break;
 case'/':act4(x,y);break;
 default:printf("Enter date error!\n");
 }
 return 0;
 }
 void act1(float x,float y)
 {
 printf("x+y=%f\n",x+y);
 }
 void act2(float x,float y)
 {
 printf("x-y=%f\n",x-y);
 }
 void act3(float x,float y)
 {
 printf("x*y=%f\n",x*y);
 }
 void act4(float x,float y)
 {
 printf("x/y=%f\n",x/y);
 }

