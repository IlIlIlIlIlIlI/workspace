#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
  int abc, def, ghi;
  int a[10], count = 0;

  memset(a, 0, sizeof(a));
 // printf("n\n");
  for(abc = 123; abc <= 329; abc++)
  {
     def = 2*abc;
     ghi = 3*abc;

     a[abc/100] = a[abc/10%10] = a[abc%10] = 1;
     a[def/100] = a[def/10%10] = a[def%10] = 1;
     a[ghi/100] = a[ghi/10%10] = a[ghi%10] = 1;
     int i;
     for( i = 1; i <= 9; i++)
        count += a[i];

     if(count == 9) printf("%d %d %d\n", abc, def, ghi);
     count = 0;
     memset(a, 0, sizeof(a));
  }
  return 0;
}
