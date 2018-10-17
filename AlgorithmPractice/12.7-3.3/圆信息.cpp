 #include<stdio.h>
 #define pi 3.14159
 int main()
 {
     float r;
    scanf("%f",&r);
    if(0 < r <= 10000)
      printf("%.4f %.4f %.4f",2*r,2*pi*r,pi*r*r);
    return 0;
 }


