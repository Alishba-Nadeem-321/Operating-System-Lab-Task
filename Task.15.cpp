#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Process {
    std::string id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int wait_time;
};

void schedule_fcfs(std::vector<Process>& processes) {
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
    });

    int current_time = 0;
    double total_wait = 0;

    std::cout << "PID | Arrival | Burst | Completion | Turnaround | Wait\n";
    for (auto& p : processes) {
        if (current_time < p.arrival_time) {
            current_time = p.arrival_time;
        }
        p.completion_time = current_time + p.burst_time;
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.wait_time = p.turnaround_time - p.burst_time;
        current_time = p.completion_time;
        total_wait += p.wait_time;

        std::cout << p.id << " | " << p.arrival_time << " | " << p.burst_time 
                  << " | " << p.completion_time << " | " << p.turnaround_time 
                  << " | " << p.wait_time << "\n";
    }
    std::cout << "Average Waiting Time : " << std::fixed << std::setprecision(2) << total_wait / processes.size() << " ms\n";
}

int main() {
    std::vector<Process> processes = {
        {"P1", 0, 5},
        {"P2", 1, 3},
        {"P3", 2, 8}
    };
    schedule_fcfs(processes);
    return 0;
}