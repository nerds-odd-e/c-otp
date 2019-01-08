#include "queue.h"
#include <stdlib.h>

queue *queue_malloc() {
    return (queue*)malloc(sizeof(queue));
}

void queue_free(queue *q) {
    free(q);
}

