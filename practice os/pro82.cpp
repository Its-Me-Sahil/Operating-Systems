#include<iostream>
using namespace std;
int n,fs,pages[20],lastused[20],frames[20],available,index,count=0;
int main()
{
    cout<<"Enter the total number of references to string";
    cin>>n;
    cout<<"Enter the total number of frames";
    cin>>fs;
    cout<<"Enter the reference page";
    for(int i=0; i<n; i++)
    {
        cin>>pages[i];
    }
    for(int i=0; i<n; i++)
    {
        frames[i] =0;
        lastused[i] =0;
    }
    cout<<"\n\npages\tframes\n";
    for(int i=0; i<n; i++)
    {
        available=0;
        cout<<pages[i]<<"\t";
        for(int k=0;k<fs;k++)
        {
            if(frames[k]==pages[i])
            {
                lastused[k] =i+1;
                available=1;
            }
        }
        if(available==0)
        {
           int min=lastused[0];
            index=0;
            for(int k=0;k<fs;k++)
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
        for(int k=0;k<fs;k++)
        {
            cout<<frames[k];
        }
        cout<<"\n";

    }
    cout<<"total number of pages fault is "<<count;
}