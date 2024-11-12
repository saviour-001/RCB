#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define PRODUCER_COUNT 2
#define CONSUMER_COUNT 2

int buffer[BUFFER_SIZE];
int count = 0;  // buffer count

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

void* producer(void* param);
void* consumer(void* param);

int main() {
    pthread_t producers[PRODUCER_COUNT];
    pthread_t consumers[CONSUMER_COUNT];

    // Initialize mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer threads
    for (int i = 0; i < PRODUCER_COUNT; i++) {
        pthread_create(&producers[i], NULL, producer, NULL);
    }

    // Create consumer threads
    for (int i = 0; i < CONSUMER_COUNT; i++) {
        pthread_create(&consumers[i], NULL, consumer, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < PRODUCER_COUNT; i++) {
        pthread_join(producers[i], NULL);
    }
    for (int i = 0; i < CONSUMER_COUNT; i++) {
        pthread_join(consumers[i], NULL);
    }

    // Destroy mutex and semaphores
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

void* producer(void* param) {
    int item;
    while (1) {
        item = rand() % 100;  // produce an item
        sem_wait(&empty);  // wait for empty slot
        pthread_mutex_lock(&mutex);  // acquire mutex

        // Add item to buffer
        buffer[count++] = item;
        printf("Produced: %d\n", item);

        pthread_mutex_unlock(&mutex);  // release mutex
        sem_post(&full);  // signal full slot

        sleep(1);  // simulate production time
    }
    return NULL;
}

void* consumer(void* param) {
    int item;
    while (1) {
        sem_wait(&full);  // wait for full slot
        pthread_mutex_lock(&mutex);  // acquire mutex

        // Remove item from buffer
        item = buffer[--count];
        printf("Consumed: %d\n", item);

        pthread_mutex_unlock(&mutex);  // release mutex
        sem_post(&empty);  // signal empty slot

        sleep(1);  // simulate consumption time
    }
    return NULL;
}
