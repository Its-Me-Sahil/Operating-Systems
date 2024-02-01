//3: PROGRAM TO IMPLEMENT PREEMTIVE PRIORITY WITH ARRIVAL TIME :
#include<iostream>
using namespace std;
void PS(double brst[], double arr[], int pri[], int n)
{
    double WT[10] = {0}, TT[10] = {0}, CT[10] = {0}, remTime[10]= {0};
    double avgWT = 0, avgTT = 0;
    for(int i = 1; i <= n; i++)
        remTime[i] = brst[i];

    int complete = 0, t = 0, minm = 999;
    int index = 0, compTime;
    bool done = false;
    while (complete != n)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((arr[j] <= t) && (pri[j] < minm) && remTime[j] > 0)
            {
                minm = pri[j];
                index = j;
                done = true;
            }
        }
        if (done == false)
        {
            t++;
            continue;
        }
        remTime[index]--;
        minm = remTime[index];
        if (remTime[index] == 0)
        {
            minm = 999;
            complete++;
            done = false;
            compTime = t + 1;
            WT[index] = compTime - brst[index] - arr[index];

            if (WT[index] < 0)
                WT[index] = 0;
        }
        t++;
    }
    for(int i = 1; i <= n; i++)
    {
        TT[i] = WT[i] + brst[i];
        avgWT += WT[i];
        avgTT += TT[i];
    }
    cout << "\nProcess\t\tWaiting Time\t\t Turn Around Time" << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << "P" << i << "\t\t";
        cout << WT[i] << "\t\t\t ";
        cout << TT[i] << endl;
    }
    cout << "\t\tAvg WT = " << avgWT/n;
    cout << "\t\tAvg TT = " << avgTT/n;
}
int main()
{
    cout<<"\nPROGRAM TO IMPLEMENT PREEMTIVE PRIORITY WITH ARRIVAL TIME\n";
    int n, pri[10];
    double arr[10], brst[10];
    cout << "Enter the number of processes : ";
    cin >> n;
    cout << "\n-- Arrival Time --\n";
    for(int i = 1; i <= n; i++)
    {
        cout << "Process " << i << " : ";
        cin >> arr[i];
    }
    cout << "\n-- Burst Time --\n";
    for(int i = 1; i <= n; i++)
    {
        cout << "Process " << i << " : ";
        cin >> brst[i];
    }

    cout << "\n-- Priority --\n";
    for(int i = 1; i <= n; i++)
    {
        cout << "Process " << i << " : ";
        cin >> pri[i];
    }
    PS(brst, arr, pri, n);
    return 0;
}

