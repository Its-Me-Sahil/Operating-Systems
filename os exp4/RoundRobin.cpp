#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream> // Include the stringstream header
#include "grid_format.h"
#define MAX 10
using namespace std;

struct Process
{
    string name;
    double arrival_time;
    double burst_time;
    bool visited;
};

int findLastOccurrenceOf(vector<pair<string, double>> GanttChart, int key)
{
    int value;
    for (int i = GanttChart.size() - 1; i >= 0; i--)
    {
        if (GanttChart[i].first == "P" + to_string(key))
        {
            value = GanttChart[i].second;
            return value;
        }
    }
}

void computeDetails(int fp, vector<pair<string, double>> GanttChart, vector<Process> P)
{
    float avgWT = 0;
    float avgTT = 0;
    double burst_time[MAX] = {0};
    double arrival_time[MAX] = {0};
    double waiting_time[MAX] = {0};
    double completion_time[MAX] = {0};
    double turn_around_time[MAX] = {0};

    for (int i{1}; i <= P.size(); i++)
    {
        completion_time[i - 1] = findLastOccurrenceOf(GanttChart, i);
    }
    for (int i{0}; i < P.size(); i++)
    {
        burst_time[i] = P[i].burst_time;
        arrival_time[i] = P[i].arrival_time;

        waiting_time[i] = completion_time[i] - P[i].burst_time - P[i].arrival_time;
        turn_around_time[i] = waiting_time[i] + P[i].burst_time;

        avgWT += waiting_time[i];
        avgTT += turn_around_time[i];
    }
    vector<string> v = {"Process", "BurstTime", "ArrivalTime", "WaitingTime", "TurnAroundTime"};

    grid::printDetailsTable(P.size(), v, arrival_time, burst_time, waiting_time, turn_around_time);

    cout << "-> Average waiting time     : " << avgWT / P.size() << endl
         << "-> Average turn around time : " << avgTT / P.size();

    grid::printGanttChart(fp, GanttChart);
}

void checkNextProcess(int n, int time, queue<Process> &readyQueue, vector<Process> &processes, double time_quantum)
{
    for (int i{}; i < processes.size(); i++)
    {
        if ((processes[i].arrival_time <= time) && (!processes[i].visited))
        {
            readyQueue.push(processes[i]);
            processes[i].visited = true;
        }
    }
}

void roundRobinScheduling(vector<Process> &processes, double time_quantum)
{
    double time = 0;
    int n = processes.size;
    int fp = 0;
    queue<Process> readyQueue;
    vector<pair<string, double>> GanttChart;

    while (!readyQueue.empty() || !processes.empty())
    {
        checkNextProcess(n, time, readyQueue, processes, time_quantum);

        if (readyQueue.empty())
        {
            bool flag = false;
            time++;

            for (int i = 0; i < n; i++)
            {
                if (processes[i].visited)
                {
                    flag = true;
                }
                if (!processes[i].visited)
                {
                    flag = false;
                }
            }

            if (flag)
            {
                computeDetails(fp, GanttChart, processes);
                exit(1);
            }
        }
        else
        {
            static int first = 0;
            Process current_process = readyQueue.front();
            readyQueue.pop();

            double execution_time = min(time_quantum, current_process.burst_time);
            current_process.burst_time -= execution_time;
            time += execution_time;

            if (first == 0)
            {
                fp = current_process.arrival_time;
                first++;
            }
            GanttChart.push_back(make_pair(current_process.name, time));

            if (current_process.burst_time > 0)
            {
                checkNextProcess(n, time, readyQueue, processes, time_quantum);
                readyQueue.push(current_process);
            }
        }
    }
}

int main()
{
    int n;
    int time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    cout << "-> Enter the Arrival Time: ";
    for (int i{}; i < n; i++)
    {
        cin >> processes[i].arrival_time;

        // Convert integer to string using stringstream
        stringstream ss;
        ss << "P" << (i + 1);
        processes[i].name = ss.str();

        processes[i].visited = false;
    }

    cout << "-> Enter the Burst Time: ";
    for (int i{}; i < n; i++)
    {
        cin >> processes[i].burst_time;
    }

    cout << endl << "Enter the time quantum: ";
    cin >> time_quantum;
    roundRobinScheduling(processes, time_quantum);

    return 0;
}
