//1: Program to implement Producer consumer problem with (n-1).

#include<stdio.h>
int mutex=1,empty,full=0,in=0,out=0,buffer_size,buffer[10],next_produced;
int wait(int s)
{
    while(s<0)
    {
        printf("\nCannot execute\n");
        return 0;
    }
    return s--;
}
int signal(int s)
{
    s++;
}
int producer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    if((in+1)%buffer_size==out)
    {
        printf("\nBuffer is full\n");
    }
    else
    {
        printf("\nEnter the item to be produced\n");
        scanf("%d",&next_produced);
        printf("\nThe item produced is %d",next_produced);
        buffer[in]=next_produced;
        in=(in+1)%buffer_size;
        printf("\n");
    }
    mutex=signal(mutex);
    mutex=signal(full);
}

int display()
{
    if(in==out)
    {
        printf("\nBuffer is Empty\n");


    }
    else
    {
        printf("\n Elements in buffer are :\n ");
        for(int k=0; k<buffer_size-1; k++)
        {
            printf("\n%d ",buffer[k]);
        }


    }
}

int consumer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    if(in==out)
    {
        printf("\nBuffer is Empty\n");
    }
    else
    {
        next_produced=buffer[out];
        printf("Item consumed is %d",next_produced);
        out=(out+1)%buffer_size;
        printf("\n");
    }
    mutex=signal(mutex);
    full=signal(full);
}
void main()
{
    int n;
    printf("\n Program to implement Producer consumer problem with (n-1)\n");

    printf("\nEnter the buffer size\n");
    scanf("%d",&buffer_size);
    buffer[buffer_size];
    empty=buffer_size;
    do
    {
        printf("\nEnter your choice\n1.Producer\t2.Consumer\t3.show\t 4.Exiting\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExit\n");
            break;

        default :
            printf("\nInvalid choice\n");
        }
    }
    while(n!=4);
}
