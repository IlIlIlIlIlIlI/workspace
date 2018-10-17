#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[6];
    for(int i = 0; i<6; i++)
    {
        a[i] = i;
    }
    for(int i = 0, j = 5; i < j; swap(a[i], a[j]), i++, j--);
    for(int i = 0; i < 6; i++)
    {
        printf("%d\n", a[i]);
        printf("*****\n");
    }
    return 0;
}
