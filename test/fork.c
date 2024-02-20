#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork(); // Create first child process

    if (pid1 == 0) { // First child process
        printf("Child 1: PID = %d\n", getpid());
        sleep(2); // Simulate some work
        printf("Child 1: Exiting\n");
        _exit(42); // Exit with status 42
    }

    pid2 = fork(); // Create second child process

    if (pid2 == 0) { // Second child process
        printf("Child 2: PID = %d\n", getpid());
        sleep(4); // Simulate some work
        printf("Child 2: Exiting\n");
        _exit(84); // Exit with status 84
    }

    // Parent process
    printf("Parent process: Waiting for child 1 to terminate...\n");
    int status1;
    waitpid(pid1, &status1, 0); // Wait for specific child process (pid1) to terminate
    printf("Parent process: Child 1 terminated with status: %d\n", WEXITSTATUS(status1));

    printf("Parent process: Waiting for child 2 to terminate...\n");
    int status2;
    waitpid(pid2, &status2, 0); // Wait for specific child process (pid2) to terminate
    printf("Parent process: Child 2 terminated with status: %d\n", WEXITSTATUS(status2));

    return 0;
}
