//PROGRAM FOR  DISK SCHEDULING USING FCFS
#include<stdio.h>
#include<math.h>
int main()
{
    int tdm=0,ch,n,request[10],i;
    printf("\nPROGRAM FOR  DISK SCHEDULING USING FCFS\n");
    printf("\nEnter number of requests: ");
    scanf("%d",&n);

    printf("\n\nEnter the current disk head position: ");
    scanf("%d",&ch);

    printf("\n\nEnter the requests\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&request[i]);
    }

    for(i=1;i<=n;i++)
    {
        tdm=tdm+abs(ch-request[i]);
        ch=request[i];
    }

    printf("\n\nThe total disk head movement in FCFS is %d",tdm);
}
//80 400 2300 1500 1050 2000 100 1888 1580 1700
