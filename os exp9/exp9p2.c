//PROGRAM FOR  DISK SCHEDULING USING SSTF
#include<stdio.h>
#include<math.h>
int main()
{
    int tdm=0,ch,n,request[10],i,count=0,index,dist;
    printf("\nPROGRAM FOR  DISK SCHEDULING USING SSTF\n");
    printf("\nEnter number of requests: ");
    scanf("%d",&n);

    printf("\n\nEnter the current disk head position: ");
    scanf("%d",&ch);

    printf("\n\nEnter the requests\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&request[i]);
    }

    while(count!=n)
    {
        int min=9999;
        for(i=1;i<=n;i++)
        {
            dist=abs(ch-request[i]);
            if(min>dist)
            {
                min=dist;
                index=i;
            }
        }
        tdm=tdm+min;
        ch=request[index];
        request[index]=9999;
        count++;
    }
    printf("\n\nThe total disk head movement in SSTF is %d",tdm);
}

