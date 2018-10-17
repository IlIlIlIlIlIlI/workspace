#include <stdio.h>
#define NPRIMES  1000
#define FALSE 0
#define TRUE  1
int main() {
    int n;
    int i,j,k;
    int flag;
    int primes[NPRIMES][NPRIMES];  // ����� n С������
    int level_1,level_2;  // ��ǰ��������Ŀ��1
    printf("Enter value of N > ");

    level_1 = level_2 = 0;
    for(i=2;i<=1000000;i++) {
        for(j = 0, flag = TRUE; j<level_1 && flag; j++)
            for(k = 0, flag = TRUE; k<level_2 && flag; k++)
            flag = (i%primes[j][k]);
        if (flag) {  // i ��һ������
            printf("%12d\n", i);
            if (level_1 < NPRIMES)
                if (level_2 < NPRIMES)
            primes[level_1++][level_2++] = i;
            }

    }
    return 0;
}
