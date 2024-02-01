//PROGRAM FOR  DISK SCHEDULING USING CSCAN
#include<stdio.h>
#include<math.h>
int value(int request[],int n,int ch)
{
    
    int val=0,i;
    for(i=1;i<=n;i++)
    {
        if(request[i]<ch)
        {
            val=request[i];
        }
    }
    return val;
}
int bubbleSort(int request[], int n,int ch) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (request[j] > request[j + 1]) {
                // Swap request[j] and request[j + 1]
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
       return(value(request,n,ch));
}


int main()
{
    int tdm=0,ch,n,request[10],i,count=0,index,dist,lcn,hcn,tdm1,tdm2,tdm3;
    printf("\nPROGRAM FOR  DISK SCHEDULING USING C-SCAN\n");
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

    
        tdm1=abs(ch-hcn);
        tdm2=abs(hcn-lcn);
        tdm3=abs(lcn-bubbleSort(request,n,ch));
    
    printf("\n\nThe total disk head movement in C-SCAN is %d",tdm1+tdm2+tdm3);
}

