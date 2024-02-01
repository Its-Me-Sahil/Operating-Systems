//// SJF WIHT // SJF WIHT  ARRIVAL TIME ***
#include<iostream>
using namespace std;
#define max 15
int tat[max];
int wt[max];
int Bt[max];
float AWT=0.0;
float ATAT=0.0;
int At[max];
int Po[max];
int gt[max];
void bubblesort(int n)
{
    int tbt=0,k=2,temp,min;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n-i+1; j++)
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


            }
        }
    }
    for(int i=1 ; i<=n; i++)   //starting reordering process according to less waiting time
    {
        tbt =tbt+Bt[i];         //total burst time encountered so far
        min=Bt[k];              // minimum burst time encountered so far (min).
        for(int j=k; j<=n; j++)
        {
            if(tbt >=At[j] && Bt[j]<min )      //it ck tbt  spent exc pro so far >= AT of current p (At[j]) ALSO Bt[j]) is less than the minimum burst time encountered so far (min
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

            }

        }
        k++;

    }
}
void wating_time(int n)
{
    int sum=0;
    wt[1]=0;
    for(int i=2; i<=n; i++)
    {
        sum=sum+Bt[i-1];
        wt[i]=sum-At[i];

    }


}
void cal(int n)
{
    for(int i=1; i<=n; i++)
    {
        AWT = wt[i]+AWT;
        ATAT = tat[i]+ATAT;


    }
}

void turnAtime(int n)
{
    for(int i=1; i<=n; i++)
    {
        tat[i]=wt[i]+Bt[i];
    }
}
void Display(int n)
{

    cout << "\nPROCESS\t\tBURST TIME\tARRIVAL TIME \tWAITING TIME\tTURN AROUND TIME" << endl;
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
    cout<<"\n\nAverage Waiting Time is = "<<AWT/n;
    cout<<"\nAverage Turn Arround Time is = "<<ATAT/n;

}
int main()
{
    int n;
    cout<<"\n\nPROGRAM FOR SHORTEST JOB FIRST WITH  ARRIVAL TIME :\n\n ";
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
        cout<<"Arrival  for process ["<<i<<"] =";
        cin>>At[i];
    }
    bubblesort(n);
    wating_time(n);
    turnAtime(n);
    cal(n);
    Display(n);
    return 0;
}

//output;
// PROCESS         BURST TIME      ARRIVAL TIME    WAITING TIME    TURN AROUND TIME
// P1              5               0               0               5
// P3              2               3               2               4
// P2              3               1               6               9
// P4              5               9               1               6
// P5              5               12              3               8


// Gantt Chart :
// +----------+----------+----------+----------+----------+
// |    P1    |    P3    |    P2    |    P4    |    P5    |
// +----------+----------+----------+----------+----------+
// 0         5         7         10         15         20

// Average Waiting Time is = 2.4
// // Average Turn Arround Time is = 6.4
