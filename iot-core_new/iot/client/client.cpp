#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include "IIotDaemon.h"
#include "IotDaemonProxy.h"

using namespace android;

static volatile sig_atomic_t g_interrupt = false;

static void sig_int_handler(int sig)
{
    g_interrupt = true;
}

static void wait_for_sig_int(void)
{
    while(g_interrupt == false) {
        ::usleep(100 * 1000);
    }
}

int main(void)
{
    ::signal(SIGINT, sig_int_handler);
    sp<IServiceManager> sm = defaultServiceManager();
    if(sm == NULL) {
        printf("Failed to get sm\n");
        return -1;
    }

    sp<IBinder> binder = sm->getService(IIotDaemon::descriptor);
    if(binder == NULL) {
        printf("Failed to get service\n");
        return -1;
    }

    sp<IIotDaemon> client = interface_cast<IIotDaemon>(binder);
    if(client == NULL) {
        printf("Create client failed\n");
        return -1;
    }

    android::ProcessState::self()->startThreadPool();
    client->init();
    client->open();

    wait_for_sig_int();
    client->close();

    return 0;
}
