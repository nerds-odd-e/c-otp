#include <stdio.h>
#include "queue.h"

queue *init_queue() {
    queue * q = malloc(sizeof(queue));
    q->size = 0;

    return q;
}
