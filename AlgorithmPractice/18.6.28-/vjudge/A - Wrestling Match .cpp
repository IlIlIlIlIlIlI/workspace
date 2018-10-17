#include <cstdio>
#include <string.h>
int main()
{
    int n,m,x,y;
    while(scanf("%d%d%d%d",&n,&m,&x,&y) == 4)
    {
        if(!x && !y)
        {
            printf("NO\n");
        }
        else
        {
            int numM[20000];
            memset(numM, 0, sizeof(int));
            for(int i = 0; i < 2*m; i++)
            {
                int tmp;
                scanf("%d",&tmp);
                numM[tmp] = tmp;
            }
            if(x)
            {
                int numX[n];
                for(int i = 0; i < x; i++)
                {
                    int tmp;
                    scanf("%d",&tmp);
                    numX[tmp] = tmp;
                }
            }
            if(y)
            {
                int numY[n];
                for(int i = 0; i < y; i++)
                {
                    int tmp;
                    scanf("%d",&tmp);
                    numY[tmp] = tmp;
                }
            }

        }
    }
    return 0;
}
