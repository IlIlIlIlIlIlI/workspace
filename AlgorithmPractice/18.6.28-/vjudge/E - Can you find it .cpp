#include <cstdio>
#include <string.h>

int numLNMS[4][1005];

int main()
{
    while(1)
    {
        int t = 0;
        printf("Case %d:\n",++t);
        int L,N,M,S;
        scanf("%d%d%d",&L,&N,&M);
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<L;j++)
            {
                scanf("%d",&numLNMS[i][j]);
            }
        }
        scanf("%d",&S);
        for(int i = 0;i<S;i++)
        {
            scanf("%d",&numLNMS[3][i]);
        }
        int ok[S];
        memset(ok,0,sizeof(int));
        for(int k = 0;k<S;k++)
        {
            for(int i = 0;i<3;i++)
            {
                for(int j = 0;j<L;j++)
                {
                    if(numLNMS[3][k] % numLNMS[i][j] == 0)
                    {
                        f = 1;
                    }
                }
            }
        }
    }
    return 0;
}
