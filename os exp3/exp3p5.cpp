//PROGRAM FOR NON PRE EMPTIVE PRIORITY WITH OUT ARRIVAL TIME
#include<iostream>
using namespace std;
#define max 15
int tat[max];
int wt[max];
int Bt[max];
int Pt[max];
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
            if(Pt[j]>Pt[j+1])
            {
                int temp = Pt[j];
                Pt[j] = Pt[j+1];
                Pt[j+1] = temp;

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
        wt[i]=sum;      //its basically do burst time of process one will be minus with arrival of second

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

    cout << "\nPROCESS\t\tBURST TIME\tPRIORITY \tWAITING TIME\tTURN AROUND TIME" <<endl;
    for(int i=1; i<=n; i++)
    {
        cout << "P" << Po[i] << "\t\t";
        cout<<Bt[i] << "\t\t";
        cout<<Pt[i] << "\t\t";
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

    gt[1] = 0;
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
    cout<<"\n\nPROGRAM FOR NON PRE EMPTIVE PRIORITY WITH OUT ARRIVAL TIME  :\n\n ";
    cout<<"Enter the number of Process :";
    cin>>n;

    cout<<"\nEnter the Burst Time :\n";

    for(int i=1; i<=n; i++)
    {
        Po[i]=i;
        cout<<"Burst time for process ["<<i<<"] =";
        cin>>Bt[i];

    }
    cout<<"\nEnter the priority :\n";
    for(int i=1; i<=n; i++)
    {
        cout<<"priority time for process ["<<i<<"] =";
        cin>>Pt[i];
    }
    bubblesort(n);
    WatingTime(n);
    TurnAroundTime(n);

    Display(n);
    Avg(n);
    return 0;
}

// PROCESS         BURST TIMEPRIORITY      WAITING TIME    TURN AROUND TIME
// P2              1               1               0               1
// P5              5               2               1               6
// P1              10              3               6               16
// P3              2               4               16              18
// P4              1               5               18              19


// Gantt Chart :
// +----------+----------+----------+----------+----------+
// |    P2    |    P5    |    P1    |    P3    |    P4    |
// +----------+----------+----------+----------+----------+
// 1         2         7         17         19         20

// Average turn around time : 12
// Average waiting time : 8.2
