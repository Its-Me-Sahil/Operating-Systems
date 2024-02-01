#include<iostream>
#include<math.h>
using namespace std;
int tdm=0,ch,n,request[10];
int main()
{
cout<<"Enter the total number of request";
cin>>n;
cout<<"Enter the current head position ";
cin>>ch;
cout<<"Enter the request ";
for(int i=1;i<=n;i++)
{
    cin>>request[i];	
}
for(int i=1;i<=n;i++)
{
    tdm=tdm+abs(ch-request[i]);
    ch=request[i];
}
cout<<"total number of head movement is "<<tdm<<endl;
}