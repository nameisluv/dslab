#include <stdio.h>
void toh(int n,char source,char dest,char temp)
{
    if(n>0)
    {
    toh(n-1,source,temp,dest);
    printf("\nmove disk %d from prg %c to peg %c \n",n,source,dest);
    toh(n-1,temp,dest,source);
    }
}
void main()
{
    int n;
    printf("enter the number of disks in tower of hanoi");
    scanf("%d",&n);
    toh(n,'A','C','B');
}