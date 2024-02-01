//3:PROGRAM TO IMPLEMENT WORST FIT
#include <stdio.h>

int main()
{
    int pno, bno, psize[10], bsize[10], flag[10], allocation[10], i, j, temp, largest = -1;

    printf("\n PROGRAM TO IMPLEMENT WORST FIT\n");
    printf("\nEnter the number of processes\n");
    scanf("%d", &pno);

    printf("\nEnter the number of blocks\n");
    scanf("%d", &bno);

    printf("\nEnter the size of each process\n");
    for (i = 1; i <= pno; i++)
    {
        printf("Size of process P[%d]=", i);
        scanf("%d", &psize[i]);
    }

    printf("\nEnter the size of each block\n");
    for (i = 1; i <= bno; i++)
    {
        printf("Size of block B[%d]=", i);
        scanf("%d", &bsize[i]);
    }

    for (i = 1; i <= bno; i++)
    {
        flag[i] = 0;
        allocation[i] = -1;
    }

    printf("\nProcess no\tProcess size\tBlock no\tBlock size");
    for (i = 1; i <= pno; i++)
    {
        for (j = 1; j <= bno; j++)
        {
            if (flag[j] != 1)
            {
                temp = bsize[j] - psize[i];
                if (temp >= 0)
                {
                    if (temp > largest)
                    {
                        allocation[i] = j;
                        largest = temp;
                    }
                }
            }
        }
        if (allocation[i] != -1)
        {
            flag[allocation[i]] = 1;
            printf("\n%d\t\t%d\t\t%d\t\t%d", i, psize[i], allocation[i], bsize[allocation[i]]);
        }
        else
        {
            printf("\n%d\t\t%d\t\tUnallocated\t-", i, psize[i]);
        }
        largest = -1;
    }

    return 0;
}
