#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int tdm=0,ch,n,request[10],dist,count=0,index;

cout<<"Enter the total number of request";
cin>>n;
cout<<"Enter the current head position ";
cin>>ch;
cout<<"Enter the request ";
for(int i=1;i<=n;i++)
{
    cin>>request[i];	
}
while(count!=n)
{
    int min=9999;
    for(int i=1;i<=n;i++)
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
cout<<"total number of head movement is "<<tdm<<endl;
}