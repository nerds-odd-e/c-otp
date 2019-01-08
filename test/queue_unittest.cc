#include "gtest/gtest.h"
extern "C"
{
#include "../main/queue.h"
}

namespace {

    TEST(QueueTest, init) {
        queue * q = init_queue();

        ASSERT_EQ(q->size, 0);
    }

}