//2: PROGRAM TO IMPLEMENT SHORTEST REMAINING TIME FIRST

#include <iostream>
#include <vector>
using namespace std;

struct Process
{
    int id;
    int burst_time;
    int arrival_time;
};

int main()
{
    int n;
    cout<<"\nPROGRAM TO IMPLEMENT SHORTEST REMAINING TIME FIRST\n";
    cout << "Enter the number of processes: ";

    cin >> n;

    vector<Process> processes(n);
    vector<int> remaining_time(n);
    vector<int> turnaround_time(n);
    vector<int> waiting_time(n);

    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter burst time for process P" << processes[i].id << ": ";
        cin >> processes[i].burst_time;

        remaining_time[i] = processes[i].burst_time;
    }

    for (int i = 0; i < n; i++)
    {

        cout << "Enter arrival time for process P" << processes[i].id << ": ";
        cin >> processes[i].arrival_time;
        // remaining_time[i] = processes[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    cout << "\nGantt Chart:" << endl;

    while (completed < n)
    {
        int shortest_job = -1;
        int min_remaining_time = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && remaining_time[i] > 0)
            {
                if (remaining_time[i] < min_remaining_time)
                {
                    shortest_job = i;
                    min_remaining_time = remaining_time[i];
                }
            }
        }

        if (shortest_job != -1)
        {
            cout << "| P" << processes[shortest_job].id << " ";
            remaining_time[shortest_job]--;

            if (remaining_time[shortest_job] == 0)
            {
                completed++;
                int completion_time = current_time + 1;
                turnaround_time[shortest_job] = completion_time - processes[shortest_job].arrival_time;
                waiting_time[shortest_job] = turnaround_time[shortest_job] - processes[shortest_job].burst_time;
            }
        }
        else
        {
            cout << "|    "; // No process is executing at this time
        }

        current_time++;
    }

    cout << "|" << endl;

    // Print the time below the Gantt chart
    cout << "0";
    for (int i = 1; i <= current_time; i++)
    {
        if (i < 10)
            cout << "    " << i;
        else
            cout << "   " << i;
    }
    cout << endl << endl;

    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    for (int i = 0; i < n; i++)
    {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << processes[i].id << "\t" << processes[i].burst_time << "\t\t" << processes[i].arrival_time << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}


