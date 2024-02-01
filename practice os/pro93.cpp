//scan
#include<iostream>
#include<math.h>
using namespace std;
int minimum(int request[],int n)
{
    int min=9999;
    for(int i=1;i<=n;i++)
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
    int tdm1,tdm2,ch,n,request[22],count=0,lcn,hcn;
    cout<<"Enter the total number of request";
cin>>n;
cout<<"Enter the current head position ";
cin>>ch;
cout<<"Enter the request ";
for(int i=1;i<=n;i++)
{
    cin>>request[i];
}
cout<<"Enter the higher cylinder number";
cin>>hcn;

    tdm1=abs(ch-hcn);
    tdm2=abs(hcn-minimum(request,n));

cout<<"total disk movement: "<<tdm1+tdm2;
return 0;
}