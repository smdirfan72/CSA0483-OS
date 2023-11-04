# CSA0483-OS

#1-> SYSTEM CALL INVOKING:-

ALGORITHAMIC STEPS:-

1)Include the necessary header files, such as stdio.h and unistd.h.

2)Declare two pid_t variables to store the process identifiers for the current process and the child process.

3)Use the fork() system call to create a new child process. The fork() system call will return the child's PID in the parent process and 0 in the child process.

4)Check the return value of fork():

5)If it's less than 0, the fork failed, and you should display an error message and exit.

6)If it's 0, it means you're in the child process, so you can display the child's PID using getpid() and the parent's PID using getppid().

7)If it's greater than 0, you're in the parent process, so you can display the parent's PID using getpid() and the child's PID, which is the value returned by fork().

8)Print the process identifiers and any other information you want to display.

9)End the program.

#2->COPY THE CONTENT OF ONE FILE TO OTHER:-

ALGORITHAMIC STEPS:-

1)Include the necessary header files, such as stdio.h, stdlib.h, unistd.h, and fcntl.h.

2)Define a buffer size (e.g., BUFFER_SIZE) to read and write data in chunks.

3)Declare variables to store file descriptors for the source and destination files (source_fd and dest_fd), as well as variables to store the number of bytes read and written (bytes_read and bytes_written), and a buffer to hold data.

4)Open the source file for reading using the open() system call with the O_RDONLY flag. Check for errors in opening the source file.

5)Open or create the destination file for writing using the open() system call with the O_WRONLY and O_CREAT flags. Specify file permissions (e.g., S_IRUSR | S_IWUSR) to allow reading and writing by the owner. Check for errors in opening/creating the destination file.

6)Use a loop to read data from the source file in chunks of BUFFER_SIZE bytes using the read() system call. Continue until the end of the source file is reached.Check for errors during reading.

7)Write the read data to the destination file using the write() system call. Check for errors during writing.

8)Close both the source and destination files using the close() system call.

9)Display a success message indicating that the file was copied successfully.

#3-> CPU SCHEDULING PROGRAM USING FCFS:-

ALGORITHM STEPS:-

1)Define a structure Process to represent a process with attributes like process_id, arrival_time, burst_time, completion_time, turnaround_time, and waiting_time.

2)Prompt the user to enter the number of processes (n).

3)Create an array of Process structures to store process information for n processes.

4)For each process from 1 to n:

a.Set process_id for the process.

b.Set arrival_time to 0 (since all processes start at time 0).

c.Prompt the user to enter the burst_time for the process.

5)Calculate the completion, turnaround, and waiting times for each process:

a.Initialize a variable total_waiting_time to 0.

b.For each process from 1 to n:

i.If it's the first process (i == 0), set completion_time to burst_time.

ii.Otherwise, set completion_time to the sum of the previous process's completion_time and the current process's burst_time.

iii.Calculate turnaround_time as completion_time - arrival_time.

iv.Calculate waiting_time as turnaround_time - burst_time.

v.Add the waiting_time to total_waiting_time.

6)Calculate the average waiting time as avg_waiting_time = total_waiting_time / n.

7)Print the table with columns: "Process," "Arrival Time," "Burst Time," "Completion Time," "Turnaround Time," and "Waiting Time."

8)For each process, print its details.

9)Display the average waiting time.

10)End
#4-> WAITING PROCESS WITH THE SMALLEST EXECUTION TIME TO EXECUTE NEXT:-

ALGORITHAM STEPS:-

1)Input the number of processes (num_processes).

2)Declare a structure struct Process with fields: ID, arrival time, execution time (burst time), and priority.

3)Allocate memory for an array of num_processes Process structures.

4)For each process in the array, do the following:

  a.Input the arrival time for the process.

  b.Input the execution time (burst time) for the process.
  
  c.Set the priority of the process to its execution time.

5)Sort the array of processes based on their arrival times in ascending order. This helps in scheduling processes that arrive earlier first.

6)Initialize current_time to 0 (the current time is the time elapsed so far).

7)Print the Gantt Chart header.

8)For each process in the sorted array of processes, do the following:
  
  a. Print a bar in the Gantt Chart to represent the start of the execution of the current process.
  
  b. Update current_time by adding the execution time of the current process.
  
  c. Print spaces in the Gantt Chart to represent the time interval for the execution of the current process.
  
  d. Repeat steps a-c for the next process in the sorted array.

9)Print a vertical bar to mark the end of the Gantt Chart.

10)Free the allocated memory for the array of processes.

11)End.


#5-> WAITING PROCESS WITH THE HIGHEST PRIORITY TO EXECUTE NEXT:-

ALGORITHM STEPS:-

1)Initialize a data structure to store processes and their priorities (e.g., an array or a priority queue).

2)Insert processes into the data structure with their respective priorities.

3)Build the data structure into a max-heap (or equivalent priority structure).

4)Repeat the following steps until there are no more processes in the data structure:

  a. Extract the process with the highest priority from the data structure.
  
  b. Execute the extracted process.
  
  c. If there are more processes in the data structure, go back to step 4a.
  
5)Finish when all processes have been executed.


#6-> IMPLMENTING PRE-EMPTIVE PRIORITY SCHEDULING ALGORITHM:-

ALGORITM STEPS:-

1)Initialize data structures to store process information, such as arrival time, burst time, priority, completion time, turnaround time, and waiting time.

2)Input the number of processes (n).

3)For each process i from 1 to n, do:
  
  a. Input the arrival time, burst time, and priority of the process.
  
  b. Initialize the burst time for process i.
  
  c. Calculate the total burst time (total_burst_time) by summing up the burst times of all processes.

4)Initialize the current time (current_time) to 0.

5)While current_time is less than total_burst_time, do:
  
  a.Find the process with the highest priority among the processes that have arrived and have remaining burst time (use the findHighestPriority function):
   
   i. Initialize highest_priority to -1 and highest_priority_process to -1.
   
   ii. For each process i from 1 to n, do:
   
   - If the process has arrived (arrival_time <= current_time) and has remaining burst time (burst_time > 0):
   
   - If the process's priority is higher than the current highest_priority or if highest_priority is -1 (indicating the first process found), update 
     highest_priority and highest_priority_process.
   
   iii. highest_priority_process now represents the process to be executed next.
  
  b. If no process is found in step 5a, increment current_time by 1 (idle CPU time).
  
  c. If a process is found in step 5a, execute it by decrementing its burst time by 1 and updating current_time.
    
   i. If the process's burst time becomes 0, calculate its completion time, turnaround time, and waiting time.

6)Display the process details, including their arrival time, burst time, priority, completion time, turnaround time, and waiting time for all processes.


#7-> IMPLEMENTATION OF NON PREEMPTIVE SJF ALGORITHM:-

ALGORITHM STEPS:-

1)Create an array of struct Process to store process information.

2)For each process i from 1 to n:
    
   a.Read the arrival time for the process i.
   
   b.Read the burst time for the process i.
   
   c.Initialize waitingTime[i] and turnaroundTime[i] to 0.
      Set currentTime to 0.

3)Repeat until all processes are executed:
   
   a.Initialize shortest to -1.
   
   b.For each process j from 0 to n - 1:
      
   i. If processes[j].arrivalTime <= currentTime and processes[j].burstTime > 0:
     
   - If shortest is -1 or processes[j].burstTime < processes[shortest].burstTime:
   
   - Set shortest to j.
   
   c.If shortest is -1:

   No process is available at this time, so increment currentTime by 1 (idle time).

   d. Else:

   i. Calculate waitingTime[shortest] as (currentTime - processes[shortest].arrivalTime).
   
   ii. Calculate turnaroundTime[shortest] as (waitingTime[shortest] + processes[shortest].burstTime).
   
   iii. Increment currentTime by processes[shortest].burstTime.
   
   iv. Set processes[shortest].burstTime to 0 to mark the process as completed.
     
4)Calculate the totalWaitingTime and totalTurnaroundTime by summing up the respective values for all processes.

5)Calculate the averageWaitingTime as (totalWaitingTime / n).

6)Calculate the averageTurnaroundTime as (totalTurnaroundTime / n).

7)Display the process-wise waiting time, turnaround time, average waiting time, and average turnaround time.

8)End.


#8-> SIMULATING ROUND ROBIN SCHEDULING ALGORITHM:-

ALGORITHM STEPS:-

1)Create an array of struct Process to store process information.

2)For each process i from 1 to n:
   
   a. Read the burst time for the process i.
   
   b. Initialize the remainingTime for process i with the burst time.

3)Set currentTime to 0.

4)Initialize remainingProcesses to n.

5)Repeat until all processes are completed (remainingProcesses > 0):
   
   a. For each process i from 0 to n - 1:
   
   i. If processes[i].remainingTime is greater than 0:
    
   - Calculate executeTime as the minimum of quantum and processes[i].remainingTime.
   
   - Decrement processes[i].remainingTime by executeTime.
   
   - Increment currentTime by executeTime.
   
   - Display that process i is executing for executeTime units, with its remaining time.
   
   - If processes[i].remainingTime becomes 0:
   
   - Decrement remainingProcesses by 1.
   
   - Display that process i has completed its execution.

6)Display the completion of all processes.

7)End.


#9-> INTER-PROCESS COMMUNICATION USING SHARED MEMORY:-

ALGORITHM STEPS:-

=>Producer (writer.c):

1)Start

2)Generate a unique key for the shared memory using ftok.

3)Create a shared memory segment using shmget.

4)Attach to the shared memory segment using shmat.

5)Read an integer value from the user.

6)Write the integer value to the shared memory.

7)Detach from the shared memory using shmdt.

8)End.

=>Consumer (reader.c):

1)Start

2)Generate the same unique key for the shared memory using ftok.

3)Get the shared memory segment using shmget.

4)Attach to the shared memory segment using shmat.

5)Read the integer value from the shared memory.

6)Display the value read from the shared memory.

7)Detach from the shared memory using shmdt.

8)Remove the shared memory segment using shmctl.

9)End.

#10-> INTER-PROCESS COMMUNICATION USING MESSAGE QUEUE:-

ALGORITHM STEPS:-

=>Sender (producer.c):

1)Start

2)Generate a unique key for the message queue using ftok.

3)Create or get a message queue using msgget.

4)Define a message structure with a message type (greater than 0) and a message text.

5)Prompt the user to enter a message and store it in the message structure.

6)Send the message to the message queue using msgsnd.

7)End.

=>Receiver (consumer.c):

1)Start

2)Generate the same unique key for the message queue using ftok.

3)Get the message queue using msgget.

4)Define a message structure with a message type (greater than 0) and a message text.

5)Receive a message from the message queue using msgrcv.

6)Display the received message from the message structure.

7)Remove the message queue using msgctl.

8)End.

#11-> CONCEPT OF MULTITHREADING:-

ALGORITHM STEPS:-

=>Main Program:

1)Start

2)Define constants NUM_THREADS (number of threads) and MAX_COUNT (maximum count per thread).

3)Initialize a global integer variable counter to 0 to serve as a shared counter.

4)Create a mutex using pthread_mutex_t mutex to protect the critical section.

5)Create an array of pthread_t objects named threads.

6)Create NUM_THREADS threads, each running the thread_function.

7)Wait for all threads to complete using pthread_join.

8)Display the final value of the shared counter.

9)End. =>Thread Function (thread_function):

1)Start

2)For each thread, execute the following loop MAX_COUNT times:

a. Lock the mutex using pthread_mutex_lock to enter the critical section.

b. Increment the counter by 1.

c. Unlock the mutex using pthread_mutex_unlock to exit the critical section.

3)End.

#12-> SIMULATING THE CONCEPT OF DINING-PHILOSOPHERS PROBLEM:-

ALGORITHM STEPS:-

=>Main Program:

1)Start

2)Create an array of pthread_t objects called philosophers.

3)Initialize an array of semaphores called forks, with one semaphore per philosopher.

4)Initialize a semaphore called mutex to control access to the forks.

5)Seed the random number generator.

6)For each philosopher from 0 to NUM_PHILOSOPHERS - 1, create a thread running the philosopher function and passing its ID as an argument.

7)Wait for all philosopher threads to complete using pthread_join.

8)End.

=>Philosopher Function (philosopher):

1)Start

2)Extract the philosopher's ID from the argument.

3)Define variables left_fork and right_fork for the indices of the philosopher's left and right forks.

4)Repeat indefinitely (philosopher's lifecycle):

a. Think: Output that the philosopher is thinking.

b. Sleep for a random duration to simulate thinking.

c. Pick up left fork: Wait on the forks semaphore for the left fork.

d. Output that the philosopher picked up the left fork.

e. Pick up right fork: Wait on the forks semaphore for the right fork.

f. Output that the philosopher picked up the right fork.

g. Eat: Output that the philosopher is eating.

h. Sleep for a random duration to simulate eating.

i. Put down right fork: Signal the forks semaphore for the right fork.

j. Output that the philosopher put down the right fork.

k. Put down left fork: Signal the forks semaphore for the left fork.

l. Output that the philosopher put down the left fork.

5)End


#13-> IMPLEMENTATION OF VARIOUS MEMORY ALLOCATION STRATEGIES:-

ALGORITHM STEPS:-

1) Start the program.

2) Allocate memory statically:

   a. Declare a global variable (e.g., globalVar) with a fixed size and value. This demonstrates static memory allocation.

3) Define a function stackAllocationExample():
  
   a. Inside the function, declare a local variable (e.g., stackVar) with a fixed size and value.

   b. Print the value of stackVar, which demonstrates stack allocation.

4) Define a function heapAllocationExample():

   a. Inside the function, declare a pointer to an integer (e.g., heapVar).

   b. Allocate memory for heapVar on the heap using malloc.

   c. Set a value for heapVar.

   d. Print the value of heapVar, which demonstrates heap allocation.

   e. Release the allocated memory using free.

5) In the main function:
 
   a. Call the stackAllocationExample function.
 
   b. Call the heapAllocationExample function.

6)End the program.


#14->ORGANIZING THE FILE USING SINGLE LEVEL DIRECTORY:-

ALGORITHM STEPS:-

1) Start the program.

2) Create functions for file organization:

    a. createFile():

   i. Prompt the user to enter a filename.

   ii. Attempt to create the file using fopen in write mode.

   iii. If successful, display a success message; otherwise, display an error message.

   b. listFiles():

    i. Use the system command 'ls' to list all files in the current directory.

    ii. Display the list of files to the user.

3) In the main function:

   a. Create an infinite loop to display a menu to the user:

    i. Display available options:

    - Create a file

    - List files
         
    - Exit

      ii. Prompt the user for their choice (1, 2, or 3).

      iii. Use a switch statement to perform actions based on the user's choice:

         - If the choice is 1, call the createFile() function.
         
         - If the choice is 2, call the listFiles() function to list files in the directory.
         
         - If the choice is 3, exit the program.
         
         - If the choice is invalid, display an error message and return to the menu.

4) End the program.



#15-> ORGANIZING THE FILE USING TWO LEVEL DIRECTORY STRUCTURE:-

ALGORITHM STEPS:-

1) Start the program.

2) Create functions for file organization:

    a. createUserDirectory():

    i. Prompt the user to enter a username.

    ii. Use the mkdir function to create a directory with the username as the directory name.

    iii. If successful, display a success message; otherwise, display an error message.

   b. createUserFile():

     i. Prompt the user to enter a username and a filename.

     ii. Construct the full path by combining the username and filename.

     iii. Use fopen to create the file in the specified user directory.

     iv. If successful, display a success message; otherwise, display an error message.

   c. listUserFiles():

    i. Prompt the user to enter a username.

    ii. Use the system command 'ls' to list all files in the specified user directory.
   
    iii. Display the list of files to the user.

3. In the main function:

    a. Create an infinite loop to display a menu to the user:

    i. Display available options:

    - Create a user directory
         
    - Create a user file
         
    - List user files
         
    - Exit

      ii. Prompt the user for their choice (1, 2, 3, or 4).

      iii. Use a switch statement to perform actions based on the user's choice:
        
         - If the choice is 1, call the createUserDirectory() function to create a user directory.
        
         - If the choice is 2, call the createUserFile() function to create a file within a user directory.
        
         - If the choice is 3, call the listUserFiles() function to list files in a user directory.
        
         - If the choice is 4, exit the program.
       
         - If the choice is invalid, display an error message and return to the menu.

5. End the program.

