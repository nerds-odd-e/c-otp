#include <stdlib.h>
#include "queue.h"

queue *queue_init() {
    queue * q = (queue * )malloc(sizeof(queue));
    q->size = 0;

    return q;
}

int queue_push(queue *q, int value) {
    q->values[q->size++] = value;
    return 0;
}

int queue_pop(queue *q, int *value) {
    if (q->size == 0) {
        return QUEUE_EMPTY;
    }
    *value = q->values[--q->size];
    return 0;
}
