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
