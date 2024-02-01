//program for lru
#include<iostream>
using namespace std;

int main()
{
    int pages[30],frames[30],fs,i,j,n,k,count=0,available,lastused[30],index,min;

    
    cout<<"Enter the total number of references string";
    cin>>n;
    cout<<"Enter the total no fram ";
    cin>>fs;
    cout<<"enter the pages";
    for(i=0;i<n;i++)
    {
        cin>>pages[i];
   }
   for(i=0;i<fs;i++)
   {
    frames[i] =0;
    lastused[i] =0;
   }
   cout<<"pages\t\tframes\n";
   for(i=0;i<n;i++)
   {
    available=0;
    cout<<pages[i]<<"\t\t";
    for(k=0;k<fs;k++)
    {
        if(frames[k]==pages[i])
        {
        lastused[k] =i+1;
        available=1;
        }
    }
    if(available==0)
    {
        min=lastused[0];
        index=0;
        for( k=1;k<fs;k++)
        {
            if(lastused[k]<min)
            {
                min=lastused[k];
                index=k;
            }


        }
        frames[index]=pages[i];
        lastused[index]=i+1;
        count++;

    }
    for( k=0;k<fs;k++){
    cout<<frames[k];
    }
    cout<<"\n";
    
   }
   cout<<"total number of pages fault"<<count;
   

}
