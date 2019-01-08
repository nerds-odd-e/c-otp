#include "gtest/gtest.h"

extern "C"
{
#include "../main/queue.h"
}

class QueueTest : public testing::Test {
protected:
    queue *q;

    void SetUp() {
        q = queue_init();
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
