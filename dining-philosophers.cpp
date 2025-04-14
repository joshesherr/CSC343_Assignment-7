#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t fork0 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t fork1 = PTHREAD_MUTEX_INITIALIZER;

void* philosopher0(void* arg) {
    while (1) {
        printf("Philosopher 0 is thinking...\n");
        sleep(1);

        pthread_mutex_lock(&fork0);
        pthread_mutex_lock(&fork1);

        printf("Philosopher 0 is eating.\n");
        sleep(1);

        pthread_mutex_unlock(&fork1);
        pthread_mutex_unlock(&fork0);
    }
    return NULL;
}

void* philosopher1(void* arg) {
    while (1) {
        printf("Philosopher 1 is thinking...\n");
        sleep(1);

        pthread_mutex_lock(&fork0);
        pthread_mutex_lock(&fork1);

        printf("Philosopher 1 is eating.\n");
        sleep(1);

        pthread_mutex_unlock(&fork1);
        pthread_mutex_unlock(&fork0);
    }
    return NULL;
}

int main() {
    pthread_t phil0, phil1;

    pthread_create(&phil0, NULL, philosopher0, NULL);
    pthread_create(&phil1, NULL, philosopher1, NULL);

    pthread_join(phil0, NULL);
    pthread_join(phil1, NULL);

    return 0;
}
