#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "grid_format.h"
#define MAX 10
using namespace std;
struct Process
{
    string name;
    double arrival_time;
    double burst_time;
    bool arrived;
};
double findLastOccurrenceOf(vector <pair<string, double>> GanttChart, int key)
{
    double value;
    for(int i=GanttChart.size(); i>=0; i--)
    {
        if(GanttChart[i].first == "P"+to_string(key))
        {
            value = GanttChart[i].second;
            return value;
        }
    }
}
void computeDetails(int fp, vector <pair<string, double>> GanttChart,vector <Process> P)
{
    float avgWT = 0;
    float avgTT = 0;
    double burst_time[MAX] = {0};
    double arrival_time[MAX] = {0};
    double waiting_time[MAX] = {0};
    double completion_time[MAX] = {0};
    double turn_around_time[MAX] = {0};

    for(int i{1}; i<=P.size(); i++)
    {
        completion_time[i-1] = findLastOccurrenceOf(GanttChart, i);
    }
    for(int i{0}; i<P.size(); i++)
    {
        burst_time[i] = P[i].burst_time;
        arrival_time[i] = P[i].arrival_time;
        waiting_time[i] = completion_time[i] - P[i].burst_time - P[i].arrival_time;
        turn_around_time[i] = waiting_time[i] + P[i].burst_time;
        avgWT += waiting_time[i];
        avgTT += turn_around_time[i];
    }
    vector <string> v = {"Process", "BurstTime", "ArrivalTime",  "WaitingTime", "TurnAroundTime"};

    grid::printDetailsTable(P.size(), v, arrival_time, burst_time, waiting_time, turn_around_time);
    cout << "-> Average waiting time     : " << avgWT/P.size()<< endl
         << "-> Average turn around time : " << avgTT/P.size();

    grid::printGanttChart(fp, GanttChart);
}
bool cmpBT(const Process& a, const Process& b)
{
    return a.burst_time < b.burst_time;
}
void sortQueue(queue <Process>& Q)
{
    vector <Process> temp;
    while(!Q.empty())
    {
        temp.push_back(Q.front());
        Q.pop();
    }
    sort(temp.begin(), temp.end(), cmpBT);
    for(const Process& p : temp)
    {
        Q.push(p);
    }
}
void checkArrivedProcesses(double time, vector <Process>& processes, queue <Process>& Q)
{
    for(int i{}; i<processes.size(); i++)
    {
        if((!processes[i].arrived) && (processes[i].arrival_time <= time))
        {
            processes[i].arrived = true;
            Q.push(processes[i]);
        }
    }
}
double findMinT(vector <Process> P)
{
    double min = P[0].burst_time;
    for(Process p : P)
    {
        if(p.burst_time < min)
        {
            min = p.burst_time;
        }
    }
    return min;
}
void shortestRemainingJobFirst(vector <Process>& processes)
{

    int fp = 100;
    double time = 0;
    double min_executionT = findMinT(processes);
    queue <Process> Q;
    vector <pair<string, double>> GanttChart;
    string previousProcessName = "";
    do
    {
        checkArrivedProcesses(time, processes, Q);
        sortQueue(Q);

        if(fp == 100)
        {
            fp = Q.front().arrival_time;
        }
        Q.front().burst_time -= 0.5;
        time += 0.5;
        if(Q.front().name == previousProcessName)
        {
            GanttChart.back().second = time;
        }
        else
        {
            GanttChart.push_back(make_pair(Q.front().name, time));
            previousProcessName = Q.front().name;
        }
        if(Q.front().burst_time == 0)
        {
            Q.pop();
        }

    }
    while(!Q.empty());
    computeDetails(fp, GanttChart, processes);
}

int main()
{

    int n;
    cout << "Enter the no. of processes : ";
    cin >> n;
    vector <Process> processes(n);

    cout << "  -> Enter the Arrival Time : ";
    for(int i=0; i<n; i++)
    {
        cin >> processes[i].arrival_time;
    }
    cout << "  -> Enter the Burst Time   : ";
    for(int i=0; i<n; i++)
    {
        cin >> processes[i].burst_time;
        processes[i].name = "P"+to_string(i+1);
    }
    shortestRemainingJobFirst(processes);
    return 0;
}
