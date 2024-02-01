//PROGRAM FOR NON PRE EMPTIVE PRIORITY WITH  ARRIVAL TIME
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
int At[max];

void bubblesort(int n)
{
    int tbt=0,k=2,temp,min;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n-i+1;j++)
        {
            if(At[j]>=At[j+1])
            {

                 temp = Bt[j];
                Bt[j] = Bt[j+1];
                Bt[j+1] = temp;

                temp = Po[j];
                Po[j] = Po[j+1];
                Po[j+1] = temp;

                temp = At[j];
                At[j] = At[j+1];
                At[j+1] = temp;

                 temp = Pt[j];
                Pt[j] = Pt[j+1];
                Pt[j+1] = temp;
            }
        }
    }
    for(int i=1 ;i<=n;i++)     //starting reordering process according to less waiting time
    {
        tbt =tbt+Bt[i];         //total burst time encountered so far
        min=Pt[k];              // minimum burst time encountered so far (min).
        for(int j=k;j<=n;j++)
        {
            if(tbt >=At[j] && Pt[j]<min )      //it ck tbt  spent exc pro so far >= AT of current p (At[j]) ALSO Bt[j]) is less than the minimum burst time encountered so far (min
            {
                temp = Bt[k];
                Bt[k] = Bt[j];
                Bt[j] = temp;

                temp = Po[k];
                Po[k] = Po[j];
                Po[j] = temp;

                temp = At[k];
                At[k] = At[j];
                At[j] = temp;

                temp = Pt[j];
                Pt[j] = Pt[j+1];
                Pt[j+1] = temp;

            }

        }
        k++;

    }
}
void wating_time(int n)
{
    int sum=0;
    wt[1]=0;
    for(int i=2;i<=n;i++)
    {
         sum=sum+Bt[i-1];
        wt[i]=sum-At[i];
        AWT = wt[i]+AWT;
    }


}
void turnAtime(int n)
{
    for(int i=1;i<=n;i++)
    {
        tat[i]=wt[i]+Bt[i];
        ATAT = tat[i]+ATAT;
    }
}


void  WatingTime(int n)
{
    //waiting time for process 0 is 0
    wt[1]=0;
    for(int i=2;i<=n;i++)
    {
        sum=sum+Bt[i-1];
        wt[i]=sum-At[i];      //its basically do burst time of process one will be minus with arrival of second

    }


}
void TurnAroundTime(int n)
{
    for(int i=1;i<=n;i++)
    {
        tat[i]=wt[i]+Bt[i];

    }

}
void Avg(int n)
{
    for(int i=1;i<=n;i++)
    {
        AWT =wt[i]+AWT;
        ATAT =tat[i]+ATAT;
    }
    cout<<"\n\nAverage turn around time : " << ATAT/n;
    cout<<"\nAverage waiting time : " << AWT/n;

}
void Display(int n)
{

cout << "\nPROCESS\t\tBURST TIME\tPRIORITY \tARRIVAL TIME \tWAITING TIME\tTURN AROUND TIME" <<endl;
     for(int i=1;i<=n;i++)
     {
      cout << "P" << Po[i] << "\t\t";
      cout<<Bt[i] << "\t\t";
      cout<<Pt[i] << "\t\t";
      cout<<At[i] << "\t\t";
      cout<<wt[i] << "\t\t";
      cout<<tat[i] << "\t\t"<<endl;
     }

     cout<<"\n\nGantt Chart : " << endl;
     for(int i =1;i<=n;i++)
     {
       cout << "+----------";
      }
     cout << "+";

    cout << endl << "|    ";
    for(int i = 1; i <=n; i++) {
    cout << "P" << Po[i] << "    |    ";
    }
    cout << endl;

     for(int i = 0; i < n; i++) {
    cout << "+----------";
     }
    cout << "+";

gt[1] = At[1];
for(int i = 2; i <=n+1; i++) gt[i] = gt[i-1] + Bt[i-1];

cout<<endl;
for(int i = 1; i <= n+1; i++) {
    cout << gt[i]<< "         " ;
}

}


int main()
{
    int n;
    cout<<"\n\nPROGRAM FOR NON PRE EMPTIVE PRIORITY WITH  ARRIVAL TIME  :\n\n ";
    cout<<"Enter the number of Process :";
    cin>>n;

    cout<<"\nEnter the Burst Time :\n";

    for(int i=1;i<=n;i++)
    {
        Po[i]=i;
        cout<<"Burst time for process ["<<i<<"] =";
        cin>>Bt[i];

    }
    cout<<"\nEnter the priority :\n";
    for(int i=1;i<=n;i++)
    {
        cout<<"priority time for process ["<<i<<"] =";
        cin>>Pt[i];
    }
     cout<<"\nEnter the Arrival time  :\n";
    for(int i=1;i<=n;i++)
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
// PROCESS         BURST TIME      PRIORITY        ARRIVAL TIME    WAITING TIME    TURN AROUND TIME
// P2              7               1               0               0               7
// P3              4               2               2               5               9
// P1              5               3               3               8               13


// Gantt Chart :
// +----------+----------+----------+
// |    P2    |    P3    |    P1    |
// +----------+----------+----------+
// 0         7         11         16

// Average turn around time : 9.66667
// Average waiting time : 4.33333
// PROCESS         BURST TIME      PRIORITY        ARRIVAL TIME    WAITING TIME    TURN AROUND TIME
// P1              10              3               0               0               10
// P2              1               1               1               9               10
// P3              2               1               2               9               11
// P4              1               2               3               10              11


// Gantt Chart :
// +----------+----------+----------+----------+
// |    P1    |    P2    |    P3    |    P4    |
// +----------+----------+----------+----------+
// 0         10         11         13         14

// Average turn around time : 10.5
// Average waiting time : 7
