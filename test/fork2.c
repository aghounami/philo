#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Error handling
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        sleep(1);
        printf("Child process running...\n");
        sleep(1);
        _exit(5); // Exit with status 5 (not 0
        // Child process exits with status 5
        return 5;
    } else {
        // Parent process
        printf("Parent process waiting for child...\n");
        int status;
        waitpid(pid, &status, 0);

            printf("Child process terminated with status: %d\n", status);
    }

    return 0;
}
