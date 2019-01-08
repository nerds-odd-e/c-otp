#ifndef C_OTP_QUEUE_H
#define C_OTP_QUEUE_H

typedef struct {
    int size;
} queue;

queue * queue_init();

int queue_push(queue *q, int value);

#endif //C_OTP_QUEUE_H
