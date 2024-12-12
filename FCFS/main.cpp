#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};


void fcfsScheduling(vector<Process>& processes) {
    int currentTime = 0;

    for (int i = 0; i < processes.size(); i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        processes[i].turnaroundTime = currentTime - processes[i].arrivalTime;
    }
}


void displayResults(const vector<Process>& processes) {
    cout << "ProcessID\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime\n";
    for (const Process& p : processes) {
        cout << p.id << "\t\t" << p.arrivalTime << "\t\t" << p.burstTime
             << "\t\t" << p.waitingTime << "\t\t" << p.turnaroundTime << endl;
    }
}

int main() {
    srand(time(0));
    vector<Process> processes(96);
    for (int i = 0; i < 96; i++) {
        processes[i].id = i + 1;
        processes[i].arrivalTime = rand() % 50;
        processes[i].burstTime = rand() % 20 + 1;
    }


    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });


    fcfsScheduling(processes);
    displayResults(processes);

    return 0;
}
