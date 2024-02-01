//bset fit
#include<stdio.h>
int main()
{
    int pno,bno,psize[10],bsize[10],flag[10],allocation[10],i,j,temp,smallest=999,btrack[10],blockallocation[10];

    printf("\nEnter the number of processes\n");
    scanf("%d",&pno);

    printf("\nEnter the number of blocks\n");
    scanf("%d",&bno);

    printf("\nEnter the size of each process\n");
    for(i=1;i<=pno;i++)
    {
                printf("size of process P[%d]=",i);

        scanf("%d",&psize[i]);
    }

    printf("\nEnter the size of each block\n");
    for(i=1;i<=bno;i++)
    {
                printf("size of block b[%d]=",i);

         scanf("%d",&bsize[i]);
         btrack[i] = i;
         flag[j]=0;
    }

    //sorting the blocks in asscending order;
    for(i=1;i<=bno;i++)
    {
        for(j=i+1;j<=bno;j++)
        {
            if(bsize[i]>bsize[j])
            {
                temp=bsize[i];
                bsize[i]=bsize[j];
                bsize[j]=temp;
                temp=btrack[i];
                btrack[i]=btrack[j];
                btrack[j]=temp;
           

            }
        }
    }
    for(int i=1;i<=bno;i++)
    {
        printf("\nblock %d =%d",btrack[i],bsize[i]);
    }


    
for(i=1;i<=pno;i++)
   {
         for(j=1;j<=bno;j++)
         if(flag[j]!=1)
         {
            if(bsize[j]>=psize[i])
            {

               // printf("\nblock b%d has allcated to process %d",bsize[j],psize[i]);
               allocation[j]=i;
                blockallocation[j]=btrack[j];
                flag[j]=1;
                break;
            }
         }
   }
for(int i=1;i<bno;i++)
printf("\n Block %d is allocated to process =%d",blockallocation[i],allocation[i]);
}

















//     for(i=1;i<=bno;i++)
//     {
//         flag[i]=0;
//         allocation[i]=-1;
//     }

//     for(i=1;i<=pno;i++)
//     {
//         for(j=1;j<=bno;j++)
//         {
//             if(flag[j]!=1)
//             {
//                 temp=bsize[j]-psize[i];
//                 if(temp>=0)
//                 {
//                     if(smallest>temp)
//                     {
//                         allocation[i]=j;
//                         smallest=temp;
//                     }
//                 }
//             }
//         }
//         flag[allocation[i]]=1;
//         smallest=999;
//     }

//     printf("\nProcess no\tProcess size\tBlock no\tBlock size");
//     for(i=1;i<=pno && allocation[i]!=0;i++)
//     {
//         printf("\nP%d\t\t%d\t\tB%d\t\t%d",i,psize[i],allocation[i],bsize[allocation[i]]);

//     }
// }

