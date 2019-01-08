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
