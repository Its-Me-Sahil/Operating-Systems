//2:PROGRAM TO IMPLEMENT FIRST FIT
#include<stdio.h>
int main()
{
    int pno,bno,psize[10],bsize[10],flag[10],allocation[10],i,j,unallocation[10];

    printf("\nPROGRAM TO IMPLEMENT FIRST FIT \n");
    printf("\nEnter the number of processes\n");
    scanf("%d",&pno);

    printf("\nEnter the number of blocks\n");
    scanf("%d",&bno);

    printf("\nEnter the size of each process\n");
    for(i=1; i<=pno; i++)
    {
        printf("size of process P[%d]=",i);
        scanf("%d",&psize[i]);
        //  pall[i]=0;

    }

    printf("\nEnter the size of each block\n");
    for(i=1; i<=bno; i++)
    {
        printf("size of block b[%d]=",i);

        scanf("%d",&bsize[i]);
    }

    for(i=1; i<=bno; i++)
    {
        flag[i]=0;
        allocation[i]=-1;
        unallocation[i]=-1;
    }

    for(i=1; i<=pno; i++)
    {
        for(j=1; j<=bno; j++)
        {
            if(flag[j]==0 && bsize[j]>=psize[i])
            {
                allocation[j]=i;
                flag[j]=1;

                break;

            }
            else
            {
                unallocation[j]=i;
            }
        }
    }

    printf("\nBlock no\tBlock size\tProcess no\tProcess size\n");
    for(i=1; i<=bno; i++)
    {
        printf("\nB%d\t\t%d",i,bsize[i]);

        if(flag[i]==1)
        {
            printf("\t\tP%d\t\t%d",allocation[i],psize[allocation[i]]);
        }
        else
        {
            printf("\t\tp%d\t\tUnallocated",unallocation[i]);
        }
    }
}
