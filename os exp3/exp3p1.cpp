//FIRST COME FIRST SERV WITHOUT ARRIVAL TIME
#include<iostream>
using namespace std;
#define max 15
int tat[max];
int wt[max];
int bt[max];
int Po[max];
float AWT=0.0;
float ATAT=0.0;
int gt[max];
void  WatingTime(int n)
{

    //waiting time for process 0 is 0
    wt[0]=1;
    for(int i=2; i<=n; i++) {
        wt[i]=wt[i-1]+bt[i-1];

    }

}
void TurnAroundTime(int n)
{
    for(int i=1; i<=n; i++)
    {
        tat[i]=wt[i]+bt[i];

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

    cout << "\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURN AROUND TIME" << endl;
    for(int i=1; i<=n; i++)
    {
        cout << "P" <<Po[i] << "\t\t";
        cout<<bt[i] << "\t\t";
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
    for(int i = 2; i <=n+1; i++) gt[i] = gt[i-1] + bt[i-1];


    cout<<endl;
    for(int i = 1; i <= n+1; i++)
    {
        cout << gt[i]<< "         " ;
    }

}


int main()
{
    int n;
    cout<<"PROGRAM FOR FIRST COME FIRST SERV WITHOUT ARRIVAL TIME :\n\n\n ";
    cout<<"Enter the number of Process :";
    cin>>n;

    cout<<"\nEnter the Burst Time :";

    for(int i=1; i<=n; i++)
    {
        Po[i]=i;
        cout<<"\nBurst time for process ["<<i<<"] =";
        cin>>bt[i];
    }
    WatingTime(n);
    TurnAroundTime(n);

    Display(n);
    Avg(n);
    return 0;
}

// output:
// PROCESS         BURST TIME      WAITING TIME    TURN AROUND TIME
// P1              24              0               24
// P2              3               24              27
// P3              3               27              30


// Gantt Chart :
// +----------+----------+----------+
// |    P1    |    P2    |    P3    |
// +----------+----------+----------+
// 0         24         27         30

// Average turn around time : 27
// Average waiting time : 17
