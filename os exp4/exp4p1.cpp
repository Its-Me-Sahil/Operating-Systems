//1: PROGRAM TO IMPLEMENT ROUND ROBIN WITH ARRIVAL TIME
#include <iostream>
#include <climits>
using namespace std;

struct Process
{
    int AT, BT, WT, FT, TAT, pos;
};

int quant;

int main()
{
    int n, i, j;

    // Taking Input
    printf("\n PROGRAM TO IMPLEMENT ROUND ROBIN WITH ARRIVAL TIME  \n");
    cout << "Enter the no. of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter the quantum: " << endl;
    cin >> quant;

    cout << "Enter the process numbers: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].pos;

    cout << "Enter the Arrival time of processes: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].AT;

    cout << "Enter the Burst time of processes: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].BT;

    // Declaring variables
    int c = n;
    float time = 0, mini = INT_MAX, b[n], a[n];

    // Initializing burst and arrival time arrays
    int index = -1;
    for (i = 0; i < n; i++)
    {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
    }

    int tot_wt = 0;
    int tot_tat = 0;
    bool flag = false;

    while (c != 0)
    {
        mini = INT_MAX;
        flag = false;

        for (i = 0; i < n; i++)
        {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0)
            {
                index = i;
                mini = a[i];
                flag = true;
            }
        }

        // If no process is available to execute, increase time
        if (!flag)
        {
            time++;
            continue;
        }

        if (b[index] <= quant)
        {
            time += b[index];
            b[index] = 0;
        }
        else
        {
            time += quant;
            b[index] -= quant;
        }

        if (b[index] > 0)
        {
            a[index] = time + 0.1;
        }

        if (b[index] == 0)
        {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    } // end of while loop

    // Printing output
    cout << "Process number ";
    cout << "Arrival time ";
    cout << "Burst time ";
    cout << "\tWait Time ";
    cout << "\tTurnAround Time" << endl;

    for (i = 0; i < n; i++)
    {
        cout << p[i].pos << "\t\t";
        cout << p[i].AT << "\t\t";
        cout << p[i].BT << "\t";
        cout << p[i].WT << "\t\t";
        cout << p[i].TAT << endl;
    }

    // Calculating average wait time and turnaround time
    double avg_wt, avg_tat;
    avg_wt = tot_wt / static_cast<double>(n);
    avg_tat = tot_tat / static_cast<double>(n);

    // Printing average wait time and turnaround time
    cout << "The average wait time is: " << avg_wt << endl;
    cout << "The average TurnAround time is: " << avg_tat << endl;

    return 0;
}
