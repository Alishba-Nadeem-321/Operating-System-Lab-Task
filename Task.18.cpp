#include <iostream>
#include <vector>
#include <queue>

struct Process {
    std::string id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int wait_time;
    bool in_queue = false;
};

void schedule_round_robin(std::vector<Process>& processes, int quantum) {
    std::queue<int> q;
    int current_time = 0, completed = 0, n = processes.size();

    for (int i = 0; i < n; ++i) {
        if (processes[i].arrival_time == 0) {
            q.push(i);
            processes[i].in_queue = true;
        }
    }

    std::cout << "Quantum = " << quantum << "\nExecution : ";
    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        Process& p = processes[idx];
        int slice = std::min(quantum, p.remaining_time);
        p.remaining_time -= slice;
        current_time += slice;

        std::cout << p.id << " (" << slice << " ms ) " << (p.remaining_time == 0 && completed == n - 1 ? "\n" : "-> ");

        for (int i = 0; i < n; ++i) {
            if (i != idx && processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && !processes[i].in_queue) {
                q.push(i);
                processes[i].in_queue = true;
            }
        }

        if (p.remaining_time > 0) {
            q.push(idx);
        } else {
            p.completion_time = current_time;
            p.turnaround_time = p.completion_time - p.arrival_time;
            p.wait_time = p.turnaround_time - p.burst_time;
            completed++;
        }
    }

    std::cout << "PID | Turnaround | Wait\n";
    for (const auto& p : processes) {
        std::cout << p.id << " | " << p.turnaround_time << " | " << p.wait_time << "\n";
    }
}

int main() {
    std::vector<Process> processes = {
        {"P1", 0, 3, 3},
        {"P2", 0, 2, 2},
        {"P3", 0, 4, 4}
    };
    schedule_round_robin(processes, 2);
    return 0;
}