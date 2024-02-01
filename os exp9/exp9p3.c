//PROGRAM FOR  DISK SCHEDULING USING SCAN
#include<stdio.h>
#include<math.h>

int minimum(int request[],int n)
{
    int min=9999,i;
    for(i=1;i<=n;i++)
    {
        if(request[i]<min)
        {
            min=request[i];
        }
    }
    return min;
}

int main()
{
    int tdm=0,ch,n,request[10],i,count=0,index,dist,lcn,hcn,tdm1,tdm2;
    printf("\nPROGRAM FOR  DISK SCHEDULING USING SCAN\n");
    printf("\nEnter number of requests: ");
    scanf("%d",&n);

    printf("\n\nEnter the current disk head position: ");
    scanf("%d",&ch);

    printf("\n\nEnter the requests\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&request[i]);
    }

    printf("\n\nEnter the lowest cylinder number: ");
    scanf("%d",&lcn);

    printf("\n\nEnter the highest cylinder number: ");
    scanf("%d",&hcn);

    for(i=1;i<=n;i++)
    {
        tdm1=abs(ch-hcn);
        tdm2=abs(hcn-minimum(request,n));
    }
    printf("\n\nThe total disk head movement in SCAN is %d",tdm1+tdm2);
}

