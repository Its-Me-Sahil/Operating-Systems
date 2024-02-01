#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string> // Added to fix 'to_string' error
using namespace std;

#define MAX 10

struct Process {
    string pname;
    double art;
    double bt;
    bool visited;
};

void disptable(int n, int fp, double bt[], double at[], double wt[], double tt[], vector<pair<string, double> > gchart) {
    cout << "Process\t\tBurst Time\tArrival Time\tWaiting Time\tTurnAround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "p" << i + 1 << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t" << tt[i] << endl;
    }
    cout << endl;
    cout << "Gantt Chart: " << endl << "|  ";
    for (int i = 0; i < gchart.size(); i++) {
        cout << gchart[i].first << "  |  ";
    }
    cout << endl << fp;
    for (int i = 0; i < gchart.size(); i++) {
        cout << "      " << gchart[i].second;
    }
    cout << endl;
}

int lastoccurrence(vector<pair<string, double> > gchart, int key) {
    int value = -1; // Default value if not found
    for (int i = gchart.size() - 1; i >= 0; i--) {
        if (gchart[i].first == "P" + std::to_string(key)) {
            value = gchart[i].second;
            return value;
        }
    }
    return value; // Return the default value if not found
}

void calcs(int fp, vector<pair<string, double> > gchart, vector<Process> P) {
    float avgWT = 0;
    float avgTT = 0;
    double bt[MAX] = {0};
    double art[MAX] = {0};
    double wt[MAX] = {0};
    double compt[MAX] = {0};
    double tt[MAX] = {0};

    for (int i = 1; i <= P.size(); i++) {
        compt[i - 1] = lastoccurrence(gchart, i);
    }
    for (int i = 0; i < P.size(); i++) {
        bt[i] = P[i].bt;
        art[i] = P[i].art;
        wt[i] = compt[i] - P[i].bt - P[i].art;
        tt[i] = wt[i] + P[i].bt;
        avgWT += wt[i];
        avgTT += tt[i];
    }

    disptable(P.size(), fp, bt, art, wt, tt, gchart);
    cout << "-> Average waiting time     : " << avgWT / P.size() << endl;
    cout << "-> Average turn around time : " << avgTT / P.size();
}

void nextprocess(int n, double time, queue<Process> &readyQueue, vector<Process> &p, double ts) {
    for (int i = 0; i < p.size(); i++) {
        if ((p[i].art <= time) && (!p[i].visited)) {
            readyQueue.push(p[i]);
            p[i].visited = true;
        }
    }
}

void rr(vector<Process> &p, double ts) {
    double time = 0;
    int n = p.size();
    int fp = 0;
    queue<Process> readyQueue;
    vector<pair<string, double> > gchart;

    while (!readyQueue.empty() || !p.empty()) {
        nextprocess(n, time, readyQueue, p, ts);
        if (readyQueue.empty()) {
            bool flag = false;
            time++;
            for (int i = 0; i < n; i++) {
                if (p[i].visited) {
                    flag = true;
                }
                if (!p[i].visited) {
                    flag = false;
                }
            }
            if (flag) {
                calcs(fp, gchart, p);
                exit(1);
            }
        } else {
            static int first = 0;
            Process current_process = readyQueue.front();
            readyQueue.pop();

            double execution_time = min(ts, current_process.bt);
            current_process.bt -= execution_time;
            time += execution_time;

            if (first == 0) {
                fp = current_process.art;
                first++;
            }
            gchart.push_back(make_pair(current_process.pname, time));

            if (current_process.bt > 0) {
                nextprocess(n, time, readyQueue, p, ts);
                readyQueue.push(current_process);
            }
        }
    }
}

int main() {
    int n;
    int ts;
    cout << "Enter the no. of processes: ";
    cin >> n;
    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Process P" << i + 1 << " : " << endl;
        cout << "==> Arrival Time: ";
        cin >> p[i].art;
        cout << "==> Burst Time  : ";
        cin >> p[i].bt;
        p[i].pname = "P" + std::to_string(i + 1);
        p[i].visited = false;
        cout << endl;
    }
    cout << endl << "Enter the time quantum: ";
    cin >> ts;
    rr(p, ts);
    return 0;
}
