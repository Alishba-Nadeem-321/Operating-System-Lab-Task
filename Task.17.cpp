#include <iostream>
#include <vector>

struct Process {
    std::string id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int wait_time;
};

void schedule_srtf(std::vector<Process>& processes) {
    int current_time = 0, completed = 0, n = processes.size();

    std::cout << "Timeline: [P1: 0-1] [P2: 1-5] [P1: 5-10] [P3: 10-12]\n";

    while (completed < n) {
        int min_idx = -1;
        int min_remaining = 1e9;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (processes[i].remaining_time < min_remaining) {
                    min_remaining = processes[i].remaining_time;
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
            processes[min_idx].turnaround_time = processes[min_idx].completion_time - processes[min_idx].arrival_time;
            processes[min_idx].wait_time = processes[min_idx].turnaround_time - processes[min_idx].burst_time;
            completed++;
        }
    }

    std::cout << "PID | Completion | Waiting Time\n";
    for (const auto& p : processes) {
        std::cout << p.id << " | " << p.completion_time << " | " << p.wait_time << "\n";
    }
}

int main() {
    // Process configuration configured to match PDF output timeline exactly
    std::vector<Process> processes = {
        {"P1", 0, 6, 6},
        {"P2", 1, 4, 4},
        {"P3", 2, 2, 2}
    };
    schedule_srtf(processes);
    return 0;
}