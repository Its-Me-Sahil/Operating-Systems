// SJF WIHT OUT ARRIVAL TIME
#include<iostream>
using namespace std;
#define max 15
int tat[max];
int wt[max];
int Bt[max];
float AWT=0.0;
float ATAT=0.0;
int Po[max];
int gt[max];
void bubblesort(int n)
{

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n-i+1; j++)
        {
            if(Bt[j]>Bt[j+1])
            {

                int  temp = Bt[j];
                Bt[j] = Bt[j+1];
                Bt[j+1] = temp;

                temp = Po[j];
                Po[j] = Po[j+1];
                Po[j+1] = temp;


            }
        }
    }
}
void wating_time(int n)
{
    wt[1]=0;
    for(int i=2; i<=n; i++)
    {
        wt[i]=wt[i-1]+Bt[i-1];
        AWT = wt[i]+AWT;
    }


}
void turnAtime(int n)
{
    for(int i=1; i<=n; i++)
    {
        tat[i]=wt[i]+Bt[i];
        ATAT = tat[i]+ATAT;
    }
}
void Display(int n)
{

    cout << "\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURN AROUND TIME" << endl;
    for(int i=1; i<=n; i++)
    {
        cout << "P" << Po[i] << "\t\t";
        cout<<Bt[i] << "\t\t";
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
    cout<<"\n\nAverage Waiting Time is = "<<AWT/n;
    cout<<"\nAverage Turn Arround Time is = "<<ATAT/n;

}
int main()
{
    int n;
    cout<<"\n\nPROGRAM FOR SHORTEST JOB FIRST WITHOUT ARRIVAL TIME :\n\n ";
    cout<<"Enter the number of Process :";
    cin>>n;

    cout<<"\nEnter the Burst Time :\n";

    for(int i=1; i<=n; i++)
    {
        Po[i]=i;
        cout<<"Burst time for process ["<<i<<"] =";
        cin>>Bt[i];

    }
    bubblesort(n);
    wating_time(n);
    turnAtime(n);
    Display(n);
    return 0;
}

//output;
// ROCESS         BURST TIME      WAITING TIME    TURN AROUND TIME
// P4              3               0               3
// P1              6               3               9
// P3              7               9               16
// P2              8               16              24


// Gantt Chart :
// +----------+----------+----------+----------+
// |    P4    |    P1    |    P3    |    P2    |
// +----------+----------+----------+----------+
// 0         3         9         16         24

// Average Waiting Time is = 7
// Average Turn Arround Time is = 13
