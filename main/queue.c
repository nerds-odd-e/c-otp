#include <stdio.h>
#include "queue.h"

queue *queue_init() {
    queue * q = malloc(sizeof(queue));
    q->size = 0;

    return q;
}

int queue_push(queue *q, int value) {
    q->size += 1;
    return 0;
}
