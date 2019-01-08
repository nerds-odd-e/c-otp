#ifndef C_OTP_QUEUE_H
#define C_OTP_QUEUE_H

#include <pthread.h>

#define MAX_LEN 1000
#define QUEUE_EMPTY -1

typedef struct {
    int size;
    int values[MAX_LEN];
    int readCursor;
    int writeCursor;
    pthread_mutex_t lock;
} queue;

queue * queue_malloc();

void queue_free(queue* q);

queue * queue_init();

int queue_push(queue *q, int value);

int queue_pop(queue *q, int* value);

int queue_destroy(queue* q);

#endif //C_OTP_QUEUE_H
