#include "queue.h"

queue *queue_init() {
    queue * q = queue_malloc();
    q->size = 0;
    q->readCursor = 0;
    q->writeCursor = 0;
    pthread_mutex_init(&q->lock, NULL);

    return q;
}

int queue_push(queue *q, int value) {
    pthread_mutex_lock(&q->lock);
    q->values[q->writeCursor++] = value;
    q->size++;
    pthread_mutex_unlock(&q->lock);
    return 0;
}

int queue_pop(queue *q, int *value) {
    if (q->size == 0) {
        return QUEUE_EMPTY;
    }
    *value = q->values[q->readCursor++];
    q->size--;
    return 0;
}

