#include <iostream>
#include <vector>

struct Process {
    std::string id;
    int priority;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int completion_time;
    int wait_time;
};

void schedule_preemptive_priority(std::vector<Process>& processes) {
    int current_time = 0, completed = 0, n = processes.size();

    while (completed < n) {
        int min_idx = -1;
        int highest_priority = 1e9;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    min_idx = i;
                }
            }
        }

        if (min_idx == -1) {
            current_time++;
            continue;
        }

        processes[min_idx].remaining_time--;
        current_time++;

        if (processes[min_idx].remaining_time == 0) {
            processes[min_idx].completion_time = current_time;
            processes[min_idx].wait_time = (processes[min_idx].completion_time - processes[min_idx].arrival_time) - processes[min_idx].burst_time;
            completed++;
        }
    }

    std::cout << "PID | Priority | Burst | Arrival | Waiting Time\n";
    for (const auto& p : processes) {
        std::cout << p.id << " | " << p.priority << " | " << p.burst_time 
                  << " | " << p.arrival_time << " | " << p.wait_time << "\n";
    }
}

int main() {
    std::vector<Process> processes = {
        {"P1", 2, 4, 0, 4},
        {"P2", 1, 3, 1, 3},
        {"P3", 3, 2, 2, 2}
    };
    schedule_preemptive_priority(processes);
    return 0;
}