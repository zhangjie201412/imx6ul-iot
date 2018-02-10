#include "TestThread.h"
#include <unistd.h>

using namespace android;

int main(void)
{
    sp<TestThread> thread = new TestThread();
    thread->run("TestThread");

    while(true) {
        ::usleep(1000000);
    }
}
