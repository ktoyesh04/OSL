#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define N 5

sem_t empty, full;
int buffer[N];
int in=0, out=0, items_produced=0, items_consumed=0;

void *producer(void* arg){
    int item=1;
    while(items_produced<N){
        sem_wait(&empty);
        buffer[in] = item;
        printf("produced item %d\n", item);
        item++;
        in = (in+1)%N;
        sem_post(&full);
        usleep(1000000);
    }
}

void *consumer(void *arg){
    while(items_consumed<N){
        sem_wait(&full);
        int item = buffer[out];
        printf("consumed item %d\n", item);
        out = (out+1)%N;
        sem_post(&empty);
        usleep(1000000);
    }
}

void main(){
    pthread_t producerThread, consumerThread;
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
}
