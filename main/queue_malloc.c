#include "queue.h"
#include <stdlib.h>

queue *queue_malloc() {
    return (queue*)malloc(sizeof(queue));
}
