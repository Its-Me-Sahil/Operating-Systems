#include<iostream>
using namespace std;
#define max 20
int n,m,allocation[max][max],need[max][max],work[max],maximum[max][max],available[max],finish[max],check2=0,count=0,check1=0,s=0,seq[max];
void safesequence()
{
    cout<<"working";
    for(int i=0;i<m;i++)
    {
        work[i] =available[i];
    }
    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }
    while(count!=n)
    {
        for(int i=0;i<n;i++)
        {
            check1=0;
            for(int j=0;j<m;j++)
            {
                if((finish[i]==0) && (need[i][j]<=work[j] ))
                {
                    check1=1;
                }

            }
            if(check1==m)
            {
                for(int j=0;j<m;j++)
                {
                    work[j]=work[j]+allocation[i][j];
                    finish[i]=1;
                }
                seq[s]=i;
                s++;
                count++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(finish[i]==1)
        {
            check2++;
        }
    }
    if(check2==n)
    {
        cout<<"safe sequence exists here it is \n\n";
        for(int i=0;i<n;i++)
        {
            cout<<"p"<<seq[i]<<",";
        }

    }
    else{
        cout<<"no safe sequences exist";
    }

}
void display()
{
     cout << "\n Displaying the User Input:\n";
    cout << "\nDisplays ALLOCATION matrix \n";
    cout << "    ";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "   ";
        for (int j = 0; j < m; j++)
        {
            cout << allocation[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\nDisplays NEED matrix\n";
    cout << "    ";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "   ";
        for (int j = 0; j < m; j++)
        {
            cout << need[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\nDisplays max  matrix\n";
    cout << "    ";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "   ";
        for (int j = 0; j < m; j++)
        {
            cout << maximum[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << "\nDisplays available matrix :\n";
    for (int i = 1; i <= m; i++)
    {
        cout << "R" << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << available[i] << "  ";
    }
}
void input()
{
    cout<<"Enter the total number of processes";
    cin>>n;
    cout<<"Enter the number of resources";
    cin>>m;
    cout<<"Enter the values in allocation table";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>allocation[i][j];
    }

     cout<<"Enter the values in maximum table";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>maximum[i][j];
    }
    cout<<"Enter the values in work/available";
    for(int i=0;i<m;i++)
    {
        cout<<"For R"<<i+1<<":";
        cin>>available[i];
    }
    //calculate the need matrix
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        need[i][j]=(maximum[i][j]-allocation[i][j]);

    }

}
int main()
{
    cout << " program for implementing safe sequences" << endl;
    input();
    display();
    safesequence();

    return 0;
}