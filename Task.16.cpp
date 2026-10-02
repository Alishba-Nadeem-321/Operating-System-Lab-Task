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
    bool completed = false;
};

void schedule_sjf(std::vector<Process>& processes) {
    int current_time = 0, completed = 0, n = processes.size();
    double total_wait = 0;

    std::cout << "Execution Order : ";
    while (completed < n) {
        int min_idx = -1;
        int min_burst = 1e9;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= current_time && !processes[i].completed) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    min_idx = i;
                }
            }
        }

        if (min_idx == -1) {
            current_time++;
            continue;
        }

        Process& p = processes[min_idx];
        p.completion_time = current_time + p.burst_time;
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.wait_time = p.turnaround_time - p.burst_time;
        p.completed = true;
        current_time = p.completion_time;
        total_wait += p.wait_time;
        completed++;

        std::cout << p.id << (completed < n ? " -> " : "\n");
    }

    std::cout << "PID | Burst | Wait Time | Turnaround Time\n";
    for (const auto& p : processes) {
        std::cout << p.id << " | " << p.burst_time << " | " << p.wait_time 
                  << " | " << p.turnaround_time << "\n";
    }
    std::cout << "Average Waiting Time : " << std::fixed << std::setprecision(2) << total_wait / n << " ms\n";
}

int main() {
    std::vector<Process> processes = {
        {"P1", 0, 6},
        {"P2", 0, 8},
        {"P3", 0, 2}
    };
    schedule_sjf(processes);
    return 0;
}