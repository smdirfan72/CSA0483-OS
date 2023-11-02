#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct {
    int id;           
    int priority;    
    int burst_time;   
    int remaining_time; 
} Process;

void execute(Process processes[], int n) {
    int current_time = 0;
    int executed_processes = 0;

    while (executed_processes < n) {
        int highest_priority = INT_MAX;
        int next_process = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].priority < highest_priority && processes[i].burst_time > 0) {
                highest_priority = processes[i].priority;
                next_process = i;
            }
        }

        if (next_process == -1) {
            current_time++;
        } else {
            processes[next_process].remaining_time--;
            processes[next_process].burst_time--;

            printf("Time %d: Executing Process %d (Priority %d)\n", current_time, processes[next_process].id, processes[next_process].priority);

            if (processes[next_process].burst_time == 0) {
                executed_processes++;
            }
            current_time++;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    processes[0] = (Process){1, 3, 8, 8};
    processes[1] = (Process){2, 1, 6, 6};
    processes[2] = (Process){3, 4, 4, 4};
    processes[3] = (Process){4, 2, 2, 2};
    processes[4] = (Process){5, 5, 7, 7};

    int num_processes = 5;

    printf("Preemptive Priority Scheduling:\n");
    execute(processes, num_processes);

    return 0;
}
