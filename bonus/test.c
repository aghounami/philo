#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#define NUM_PHILOSOPHERS 5
#define NUM_MEALS 3

int main() {
    sem_t *forks;

    // Create a semaphore to represent the available forks
    forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, NUM_PHILOSOPHERS);
    if (forks == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    // Create philosopher processes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process (philosopher)
            int id = i;
            int meals_eaten = 0;

            while (meals_eaten < NUM_MEALS) {
                printf("Philosopher %d is thinking.\n", id);

                // Acquire left fork
                sem_wait(forks);

                // Acquire right fork
                sem_wait(forks);

                printf("Philosopher %d is eating.\n", id);
                usleep(100000); // Simulate eating time

                // Release left fork
                sem_post(forks);

                // Release right fork
                sem_post(forks);

                meals_eaten++;
            }

            printf("Philosopher %d finished meals.\n", id);
            exit(EXIT_SUCCESS);
        }
    }

    // Wait for all philosopher processes to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        wait(NULL);
    }

    // Clean up
    sem_unlink("/forks");

    return 0;
}
