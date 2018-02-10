#ifndef __TEST_THREAD_H__
#define __TEST_THREAD_H__

#include <utils/Thread.h>
#include <unistd.h>
#include <stdio.h>

namespace android {

class TestThread: public Thread
{
public:
    TestThread()
    {
        printf("++TestThread++\n");
    }
    ~TestThread()
    {

        printf("--TestThread--\n");
    }

    virtual bool threadLoop()
    {
        ::usleep(1000 * 1000);
        printf("Loop...\n");

        return true;
    }
};
};

#endif
