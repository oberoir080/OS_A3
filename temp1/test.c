#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    float *ptr1;
    float **ptr;
    int r = 2, c = 3;
    int i;
    int random=100;
    int j=0;
    ptr = (float **)malloc((r) * sizeof(float));
    for (i = 0; i < r; i++)
    {
        ptr1 = (float *)malloc((c) * sizeof(float));
      for(j=0;j<c;j++)
      {
        ptr1[j]=random+random*j*i/1000;
      }
      ptr[i]=ptr1;
        
    }
    for (i = 0; i < r; i++)
    {
        for(j = 0;j<c;j++){
            printf("%f ", ptr[i][j]);
        }
        printf("\n");
    }
    float **ptr2;
    ptr2 = (float **)malloc((r) * sizeof(float));
    for(i=0;i<r;i++){
        ptr2[i] = (float *)malloc((c) * sizeof(float));
    }
    long int res = syscall(451,(int *)ptr,(int *)ptr2,r,c);
    if (res == -1)
    {
    printf("error occured");
    return res;
    }
    printf("\n");
    for (i = 0; i < r; i++)
    {
        for(j = 0;j<c;j++){
            printf("%f ", ptr[i][j]);
        }
        printf("\n");
    }
    printf("%ld Syscalls return statement\n", res);
    return res;

}
