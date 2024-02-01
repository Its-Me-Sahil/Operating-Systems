#include <bits/stdc++.h>

namespace grid {

    void cAlign(std::string lT, std::string text, int width) { // function to center align text in a grid....
        int left = (width - text.length())/2;
        int right = width - (left + text.length());
        std::cout << lT;
        std::cout.width(left + text.length());
        std::cout.fill(' ');
        std::cout << std::fixed << std::setprecision(1) << text;
        std::cout.width(right);
        std::cout << "";
    } 
    void printDetailsTable(int n, std::vector <std::string> v, double at[], double bt[], double wt[], double tat[], int p[]) { // overloaded function, to display priority, if exists....
        for(int i{}; i<v.size(); i++) {
            std::cout << "+";
            for(int j{}; j<v[i].length()+6; j++) {
                std::cout << "-";
            }
        } std::cout << "+" << std::endl;

        for(int i{}; i<v.size(); i++) {
            std::cout << "|   " << v[i] << "   ";
        }
        std::cout << "|" << std::endl;
        
        for(int i{}; i<v.size(); i++) {
            std::cout << "+";
            for(int j{}; j<v[i].length()+6; j++) {
                std::cout << "-";
            }
        } std::cout << "+" << std::endl;
        
        for(int i{}; i<n; i++) {

            cAlign("|", "P"+std::to_string(i+1), v[0].length()+6);
            cAlign("|", std::to_string(bt[i]), v[1].length()+6);
            cAlign("|", std::to_string(at[i]), v[2].length()+6);
            cAlign("|", std::to_string(p[i]), v[3].length()+6); 
            cAlign("|", std::to_string(wt[i]), v[4].length()+6);
            cAlign("|", std::to_string(tat[i]), v[5].length()+6); 
            std::cout << "|" << std::endl;
        }
        for(int i{}; i<v.size(); i++) {
            std::cout << "+";
            for(int j{}; j<v[i].length()+6; j++) {
                std::cout << "-";
            }
        } std::cout << "+" << std::endl;
    }
    void printDetailsTable(int n, std::vector <std::string> v, double at[], double bt[], double wt[], double tat[]) {
        for(int i{}; i<v.size(); i++) {
            std::cout << "+";
            for(int j{}; j<v[i].length()+6; j++) {
                std::cout << "-";
            }
        } std::cout << "+" << std::endl;

        for(int i{}; i<v.size(); i++) {
            std::cout << "|   " << v[i] << "   ";
        }
        std::cout << "|" << std::endl;
        
        for(int i{}; i<v.size(); i++) {
            std::cout << "+";
            for(int j{}; j<v[i].length()+6; j++) {
                std::cout << "-";
            }
        } std::cout << "+" << std::endl;
        
        for(int i{}; i<n; i++) {

            cAlign("|", "P"+std::to_string(i+1), v[0].length()+6);
            cAlign("|", std::to_string(bt[i]), v[1].length()+6);
            cAlign("|", std::to_string(at[i]), v[2].length()+6);
            cAlign("|", std::to_string(wt[i]), v[3].length()+6);
            cAlign("|", std::to_string(tat[i]), v[4].length()+6); 
            std::cout << "|" << std::endl;
        }
        for(int i{}; i<v.size(); i++) {
            std::cout << "+";
            for(int j{}; j<v[i].length()+6; j++) {
                std::cout << "-";
            }
        } std::cout << "+" << std::endl;
    }
    void printGanttChart(double fp, std::vector <std::pair<std::string, double>> GanttChart) {
        std::cout << std::endl << std::endl << "Gantt Chart : " << std::endl;
        for(int i{}; i<GanttChart.size(); i++) {
            std::cout << "+----";
        }
        std::cout << "+" << std::endl << "| ";
        for(int i{}; i<GanttChart.size(); i++) {
            std::cout << GanttChart[i].first << " | ";
        }
        std::cout << std::endl;
        for(int i{}; i<GanttChart.size(); i++) {
            std::cout << "+----";
        }
        std::cout << "+" << std::endl;
        std::cout << fp;
        for(int i{}; i<GanttChart.size(); i++) {
            if(GanttChart[i].second < 10) std::cout << "  " << GanttChart[i].second;
            else std::cout << " " << GanttChart[i].second;
        }
        std::cout << std::endl;
    }
}