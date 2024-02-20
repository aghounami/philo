#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h> // For O_CREAT, O_EXCL
#include <errno.h> // For errno

int main() {
    sem_t *sem; // Semaphore pointer

    // Open or create a named semaphore
    sem = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0644, 1);
    if (sem == SEM_FAILED) {
        if (errno == EEXIST)
        {
            printf("Semaphore already exists.\n");
            sem = sem_open("/my_semaphore", 0); // Open existing semaphore
        } else {
            perror("sem_open");
            exit(EXIT_FAILURE);
        }
    }

    // Use the semaphore...
    
    // Close the semaphore
    sem_close(sem);

    return 0;
}
