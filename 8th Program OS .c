#include <stdio.h>

#define MAX_PROCESSES 20

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void roundRobinScheduling(struct Process processes[], int n, int quantum) {
    int time = 0;
    int done = 0;

    while (1) {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = 0;

                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                    printf("P%d ", processes[i].id);
                } else {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    printf("P%d ", processes[i].id);
                }
            }
        }

        if (done == 1)
            break;
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Number of processes exceeds the maximum limit.");
        return 1;
    }

    struct Process processes[n];

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nRound Robin execution order: ");
    roundRobinScheduling(processes, n, quantum);

    return 0;
}
