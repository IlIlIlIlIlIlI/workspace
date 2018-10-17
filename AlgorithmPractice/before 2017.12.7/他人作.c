
#include<stdio.h>
int main()
         {
			int x;
			int y;
			scanf("%d",&x);
			if(x>0){
				y=3*x+5;
				printf("%d",y);
			}
            if(x==0){
            	y=10;
            	printf("%d",y);
            }
            if(x<0){
            	y=x-2;
            	printf("%d",y);
            }

return 0;
            }
