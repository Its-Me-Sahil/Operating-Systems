//fifo page fault
#include<iostream>
using namespace std;
int pages[30],frames[30],fs,n,k=0,count=0,available;
int main()
{
    cout<<"Enter the total number of references string";
    cin>>n;
    cout<<"Enter the total no fram ";
    cin>>fs;
    cout<<"enter the pages";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
   }
   for(int i=0;i<fs;i++)
   {
    frames[i] =0;
   }
   cout<<"pages \t\tframes";
   for(int i=0;i<n;i++)
   {
        available=0;
        cout<<pages[i]<<"\t\t";
        for(int j=0;j<fs;j++)
        {
            if(frames[j]==pages[i])
            {
                available=1;
            }
        }
        if(available==0)
        {
            frames[k]=pages[i];
            k=(k+1)%fs;
            count++;
        }
        
        for(int i=0;i<fs;i++)
        {
            cout<<frames[i];
        }  
        cout<<"\n";
        }
        cout<<"total pages fault"<<count;
}