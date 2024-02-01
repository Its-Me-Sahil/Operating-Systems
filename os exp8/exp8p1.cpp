//Page Replacement using FIFO
#include<stdio.h>
int main()
{
    int pages[20],frame[3],i,j=0,k,available,n,fs,count=0;
    printf("\nPage Replacement using FIFO\n");

    printf("\nEnter the total number of referenced strings: ");
    scanf("%d",&n);

    printf("\n\nEnter the referenced pages\n");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&pages[i]);
    }

    printf("\nEnter the frame size: ");
    scanf("%d",&fs);

    for(i=0; i<fs; i++)
    {
        frame[i]=0;
    }

    printf("\n\nPages\tframe\n");
    for(i=1; i<=n; i++)
    {
        available=0;
        printf("%d\t",pages[i]);
        for(k=0; k<fs; k++)
        {
            if(frame[k]==pages[i])
            {
                available=1;
            }
        }
        if(available == 0)
        {
            frame[j]=pages[i];
            j=(j+1)%fs;
            count++;
        }
        for(k=0; k<fs; k++)
        {
            printf("%d ",frame[k]);
        }
        printf("\n");
    }
    printf("Total number of page faults are %d",count);
}
//3 4 3 2 1 2 6 4 5 7 4 1 3 7 7 5 4 1 3 8 5
