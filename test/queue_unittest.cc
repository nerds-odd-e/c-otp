#include "gtest/gtest.h"

extern "C"
{
#include "../main/include/queue.h"
#include <pthread.h>
#include "fff.h"
}

FAKE_VALUE_FUNC(int, pthread_mutex_init, pthread_mutex_t *, const pthread_mutexattr_t *);
FAKE_VALUE_FUNC(int, pthread_mutex_lock, pthread_mutex_t *);
FAKE_VALUE_FUNC(int, pthread_mutex_unlock, pthread_mutex_t *);
FAKE_VALUE_FUNC(int, pthread_mutex_destroy, pthread_mutex_t *);
FAKE_VALUE_FUNC(queue*, queue_malloc);
FAKE_VOID_FUNC(queue_free, queue *);

class QueueTest : public testing::Test {
protected:
    queue *q;
    queue malloc_q;

    void SetUp() {
        queue_malloc_fake.return_val = &malloc_q;
        q = queue_init();
        RESET_FAKE(pthread_mutex_lock);
        RESET_FAKE(pthread_mutex_unlock);
        RESET_FAKE(queue_malloc);
        RESET_FAKE(queue_free);
    }
};

TEST_F(QueueTest, init) {
    ASSERT_EQ(q->size, 0);
}

TEST_F(QueueTest, push) {
    int code = queue_push(q, 10);

    ASSERT_EQ(q->size, 1);
    ASSERT_TRUE(!code);
}

TEST_F(QueueTest, pushAndPop) {
    queue_push(q, 10);
    int value = 0;

    int code = queue_pop(q, &value);

    ASSERT_TRUE(!code);
    ASSERT_EQ(value, 10);
    ASSERT_EQ(q->size, 0);
}

TEST_F(QueueTest, popRightAfterInit) {
    int value = 0;

    int code = queue_pop(q, &value);

    ASSERT_EQ(code, QUEUE_EMPTY);
}

TEST_F(QueueTest, pushPushAndPop) {
    queue_push(q, 10);
    queue_push(q, 20);
    int value = 0;

    queue_pop(q, &value);

    ASSERT_EQ(value, 10);
}

TEST_F(QueueTest, pushPushPopAndPop) {
    queue_push(q, 10);
    queue_push(q, 20);
    int value = 0;
    queue_pop(q, &value);

    queue_pop(q, &value);

    ASSERT_EQ(value, 20);
}

TEST_F(QueueTest, pushPopAndPush) {
    queue_push(q, 10);
    int value = 0;
    queue_pop(q, &value);
    queue_push(q, 20);

    queue_pop(q, &value);

    ASSERT_EQ(value, 20);
}

TEST_F(QueueTest, pushLock) {
    queue_push(q, 10);

    ASSERT_EQ(pthread_mutex_lock_fake.call_count, 1);
    ASSERT_EQ(pthread_mutex_unlock_fake.call_count, 1);
}

TEST_F(QueueTest, initShouldMalloc) {
    queue malloc_q;
    queue_malloc_fake.return_val = &malloc_q;

    q = queue_init();

    ASSERT_EQ(queue_malloc_fake.call_count, 1);
    ASSERT_EQ(q, &malloc_q);
}

TEST_F(QueueTest, initShouldReturnNullCodeWhenMallocFailed) {
    queue_malloc_fake.return_val = NULL;

    q = queue_init();

    ASSERT_EQ(queue_malloc_fake.call_count, 1);
    ASSERT_EQ(q, (queue*)NULL);
}

TEST_F(QueueTest, free) {
    int code = queue_destroy(q);

    ASSERT_TRUE(!code);
    ASSERT_EQ(queue_free_fake.call_count, 1);
    ASSERT_EQ(queue_free_fake.arg0_val, q);
}
