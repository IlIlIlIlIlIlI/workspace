#include<bits/stdc++.h>
int main()
{
    int t,k;
    scanf("%d",&t);
    if(t >= 1 && t <= 20)
    {
        while(t--)
        {
            scanf("%d",&k);
            if(k >= 1 && k <= 20)
            {
                for(int i = 0;i<k;i++)
                {
                    //if(i == k)printf("Abiyoyo, Abiyoyo.");
                    /*else*/ printf("Abiyoyo, Abiyoyo.\n");
                }
                for(int j = 0;j<2;j++)
                {
                    //if(j == 2) printf("Abiyoyo, yo yoyo yo yoyo.");
                    /*else*/ printf("Abiyoyo, yo yoyo yo yoyo.\n");
                }
            }
        }
    }
}
