#include<iostream>
using namespace std;
find(int pages[],int frames[],int start,int end,int fs)
{
    int result=-1,far=-1;
    for(int i=0;i<fs;++i)
    {
        int j;
    for(j=start;j<end;++j)
    {
        if(frames[i]==pages[j])
        {
            if(j>far)
            {
                far = j;
                result=i;

            }
            break;
        }
    }
    if(j==end)
    {
        return i;
    }
    }
    return (result==-1) ? 0 : result;
}
int main()
{
    int pages[44],frames[44],fs,n,i,j,k,available,count=0;
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
        for(k=0;k<fs;k++)
        {
            if(frames[k]==pages[i])
            {
                available=1;
            }
        }
        if(available==0)
        {
            int index=find(pages,frames,i+1,n,fs);
            frames[index]=pages[i];
            count++;
        }
        for(k=0;k<fs;k++)
        {
            cout<<frames[k];
        }
        cout<<"\n";
}
cout<<"total number of pages faul"<<count;

}