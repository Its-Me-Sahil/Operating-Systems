//FIRST COME FIRST SERV WITH ARRIVAL TIME  ***
#include<iostream>
using namespace std;
#define max 15
int tat[max];
int wt[max];
int Bt[max];
int At[max];
float AWT=0.0;
float ATAT=0.0;
int Po[max];
int sum=0;
int gt[max];
void bubblesort(int n)
{

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n-i+1; j++)
        {
            if(At[j]>At[j+1])
            {
                int temp = At[j];
                At[j] = At[j+1];
                At[j+1] = temp;

                temp = Bt[j];
                Bt[j] = Bt[j+1];
                Bt[j+1] = temp;

                temp = Po[j];
                Po[j] = Po[j+1];
                Po[j+1] = temp;


            }

        }
    }


}






void  WatingTime(int n)
{
    //waiting time for process 0 is 0
    wt[1]=0;
    for(int i=2; i<=n; i++)
    {
        sum=sum+Bt[i-1];
        wt[i]=sum-At[i];      //its basically do burst time of process one will be minus with arrival of second

    }


}
void TurnAroundTime(int n)
{
    for(int i=1; i<=n; i++)
    {
        tat[i]=wt[i]+Bt[i];

    }

}
void Avg(int n)
{
    for(int i=1; i<=n; i++)
    {
        AWT =wt[i]+AWT;
        ATAT =tat[i]+ATAT;
    }
    cout<<"\n\nAverage turn around time : " << ATAT/n;
    cout<<"\nAverage waiting time : " << AWT/n;

}
void Display(int n)
{

    cout << "\nPROCESS\t\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURN AROUND TIME" << endl;
    for(int i=1; i<=n; i++)
    {
        cout << "P" << Po[i] << "\t\t";
        cout<<Bt[i] << "\t\t";
        cout<<At[i] << "\t\t";
        cout<<wt[i] << "\t\t";
        cout<<tat[i] << "\t\t"<<endl;
    }

    cout<<"\n\nGantt Chart : " << endl;
    for(int i =1; i<=n; i++)
    {
        cout << "+----------";
    }
    cout << "+";

    cout << endl << "|    ";
    for(int i = 1; i <=n; i++)
    {
        cout << "P" << Po[i] << "    |    ";
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "+----------";
    }
    cout << "+";

    gt[1] = At[1];
    for(int i = 2; i <=n+1; i++) gt[i] = gt[i-1] + Bt[i-1];

    cout<<endl;
    for(int i = 1; i <= n+1; i++)
    {
        cout << gt[i]<< "         " ;
    }

}


int main()
{
    int n;
    cout<<"\n\nPROGRAM FOR FIRST COME FIRST SERV WITH ARRIVAL TIME :\n\n ";
    cout<<"Enter the number of Process :";
    cin>>n;

    cout<<"\nEnter the Burst Time :\n";

    for(int i=1; i<=n; i++)
    {
        Po[i]=i;
        cout<<"Burst time for process ["<<i<<"] =";
        cin>>Bt[i];

    }
    cout<<"\nEnter the Arrival Time :\n";
    for(int i=1; i<=n; i++)
    {
        cout<<"Arrival time for process ["<<i<<"] =";
        cin>>At[i];
    }
    bubblesort(n);
    WatingTime(n);
    TurnAroundTime(n);

    Display(n);
    Avg(n);
    return 0;
}

// output:

// PROCESS         BURST TIME      ARRIVAL TIME    WAITING TIME    TURN AROUND TIME
// P1              5               0               0               5
// P2              3               1               4               7
// P3              2               3               5               7
// P4              5               9               1               6
// P5              5               12              3               8


// Gantt Chart :
// +----------+----------+----------+----------+----------+
// |    P1    |    P2    |    P3    |    P4    |    P5    |
// +----------+----------+----------+----------+----------+
// 0         5         8         10         15         20

// Average turn around time : 6.6
// Average waiting time : 2.6
