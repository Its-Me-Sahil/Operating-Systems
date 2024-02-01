//program for look
#include<iostream>
#include<math.h>
using namespace std;
int min(int request[], int ch)
{
    int minn=999;
    for(int i=1; i<=ch; i++)
    {
        if(request[i]<minn)
        {
            minn=request[i];
        }
    }
    return minn;

}
int max(int request[], int ch)
{
    int maxx=0;
    for(int i=1; i<=ch; i++)
    {
        if(request[i]>maxx)
        {
            maxx=request[i];
        }
    }
    return maxx;

}
int main()
{
    int tdm1,tdm2,ch,n,request[22],lcn,hcn;
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
tdm1=abs(ch-max(request,n));
tdm2=abs(max(request,n)-min(request,n));	
cout<<"total disk movement: "<<tdm1+tdm2;
}